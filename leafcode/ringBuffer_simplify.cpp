#include <iostream>
#include <algorithm>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

class UnlockQueue
{
public:
    UnlockQueue(int nSize);
    virtual ~UnlockQueue();
 
    bool Initialize();
 
    unsigned int Put(const unsigned char *pBuffer, unsigned int nLen);
    unsigned int Get(unsigned char *pBuffer, unsigned int nLen);
 
    inline void Clean() { m_nIn = m_nOut = 0; }
    inline unsigned int GetDataLen() const { return  m_nIn - m_nOut; }
 
private:
    unsigned char *m_pBuffer;    /* the buffer holding the data */
    unsigned int   m_nSize;        /* the size of the allocated buffer */
    unsigned int   m_nIn;        /* data is added at offset (in % size) */
    unsigned int   m_nOut;        /* data is extracted from off. (out % size) */
};

UnlockQueue::UnlockQueue(int nSize)
:m_pBuffer(NULL),m_nSize(nSize)
,m_nIn(0),m_nOut(0)
{}
 
UnlockQueue::~UnlockQueue()
{
    if(NULL != m_pBuffer)
    {
        delete[] m_pBuffer;
        m_pBuffer = NULL;
    }
}
 
bool UnlockQueue::Initialize()
{
    m_pBuffer = new unsigned char[m_nSize];
    if (!m_pBuffer)
        return false;
 
    m_nIn = m_nOut = 0;
    return true;
}
 
unsigned int UnlockQueue::Put(const unsigned char *buffer, unsigned int dataLen)
{
    unsigned int partLen;
 
    dataLen = std::min(dataLen, m_nSize - m_nIn + m_nOut);  //环形缓冲区的剩余容量为m_nSize - m_nIn + m_nOut，让写入的长度取len和剩余容量中较小的，避免写越界；
 
    __sync_synchronize();   //gcc提供的内存屏障函数
 
    partLen = std::min(dataLen, m_nSize - (m_nIn  % m_nSize ));
    memcpy(m_pBuffer + (m_nIn  % m_nSize ), buffer, partLen);
    /* 拷贝l 字节到fifo->buffer + fifo->in的位置上，如果l = len，则已拷贝完成，第20行len – partLen 为0，将不执行，如果l = fifo->size - (fifo->in & (fifo->size - 1)) ，则第20行还需要把剩下的 dataLen – partLen 长度拷贝到buffer的头部。 */
 
    memcpy(m_pBuffer, buffer + partLen, dataLen - partLen);
 
    __sync_synchronize();
 /* 加写内存屏障，保证in 加之前，memcpy的字节已经全部写入buffer，如果不加内存屏障，可能数据还没写完，另一个CPU就来读数据，读到的缓冲区内的数据不完全，因为读数据是通过 in – out 来判断的。 */

    m_nIn += dataLen;
 
    return dataLen;
}
 
unsigned int UnlockQueue::Get(unsigned char *buffer, unsigned int dataLen)
{
    unsigned int partLen;
    dataLen = std::min(dataLen, m_nIn - m_nOut);
 
    __sync_synchronize();
 
    partLen = std::min(dataLen, m_nSize - (m_nOut % m_nSize ));

    memcpy(buffer, m_pBuffer + (m_nOut % m_nSize ), partLen);
 
    memcpy(buffer + partLen, m_pBuffer, dataLen - partLen);     //这里如果len - l为0，那memset自然不执行了
 
    __sync_synchronize();
 
    m_nOut += dataLen;
    return dataLen;
}


/* 
参考：
https://www.xuebuyuan.com/3242624.html

使用：
    UnlockQueue unlockQueue(1024);
    unlockQueue.Initialize()
 */