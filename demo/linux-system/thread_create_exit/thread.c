/*
 * ע�⣺-pthread ѡ��
 * gcc -pthread pth.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/syscall.h>

void *thr_fn(void *arg)
{
    printf("thread 1 new thread: %d\n",syscall(SYS_gettid));
	sleep(10);
	printf("thread 1 pthread_exit: %d\n",syscall(SYS_gettid));
    pthread_exit(NULL);
}
 
void *thr_fn2(void *arg)
{
    printf("thread 2 new thread: %d\n",syscall(SYS_gettid));//1.Ҫ��ȡ�̵߳�LWP��ID����PID������gettid����	
	
    //2.  getpid() �����ڽ��̵�ID
    //3.  pthread_self() �� �̵߳��ڲ�ID
	
	sleep(15);
	printf("thread 2 pthread_exit: %d\n",syscall(SYS_gettid));
    pthread_exit(NULL);
} 
 
int main(void)
{
    int err;
    pthread_t t1;
	pthread_t t2;
	
	printf("main thread: %d\n",syscall(SYS_gettid));		
	
	//create
    err = pthread_create(&t1, NULL, thr_fn, NULL);
    if (err != 0)
        printf("can't create thread: %s\n", strerror(err));	
	
	err = pthread_create(&t2, NULL, thr_fn2, NULL);
	if (err != 0)
        printf("can't create thread: %s\n", strerror(err));
	
	//join
	if(t1 != 0)		//����Ҫ�жϣ�������߳̿���û�д����ɹ����������治���ܵȵ��Ǹ��߳̽�����
					//������pthread_join��ʱ����ֶδ��󣨷�����δ֪���ڴ�������
	{
		printf("pthread_join thread 1\n",syscall(SYS_gettid));
		pthread_join(t1,NULL);				//���̻߳����������ֱ���ȴ����߳��Ƴ�
	}
	if(t2 != 0)
	{
		printf("pthread_join thread 2\n");	
		pthread_join(t2,NULL);		
	}

	printf("main pthread_exit: %d\n",syscall(SYS_gettid));
    return EXIT_SUCCESS;
}

