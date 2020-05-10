#include "thread_pool.h"
#include <cstdio>
#include <stdlib.h>
#include <unistd.h>

class CMyTask: public CTask {	
public:
	CMyTask() = default;	
	int Run() {
		printf("%s\n", (char*)m_ptrData);
		int x = rand()%4 + 1;
		sleep(x);	
		return 0;
	}
	~CMyTask() {}
};

int main() {
	CMyTask taskObj;
	char szTmp[] = "hello!";
	taskObj.setData((void*)szTmp);
	CThreadPool threadpool(5);	//线程池大小为5
	
	for(int i = 0; i < 10; i++)
		threadpool.AddTask(&taskObj);
	
	while(1) {
		printf("There are still %d tasks need to handle\n", threadpool.getTaskSize());
		//任务队列已没有任务了
		if(threadpool.getTaskSize()==0) {
			//清除线程池
			if(threadpool.StopAll() == -1) {
				printf("Thread pool clear, exit.\n");
				exit(0);
			}
		}
		sleep(2);
      	printf("2 seconds later...\n");
	}	
	return 0;
}

/* 
输出结果

I will create 5 threads.
There are still 10 tasks need to handle
[tid: 140056759576320]	run: hello!
[tid: 140056751183616]	run: hello!
[tid: 140056742790912]	run: hello!
[tid: 140056734398208]	run: hello!
[tid: 140056767969024]	run: hello!
2 seconds later...
There are still 5 tasks need to handle
[tid: 140056742790912]	idle
[tid: 140056742790912]	run: hello!
[tid: 140056767969024]	idle
[tid: 140056767969024]	run: hello!
[tid: 140056751183616]	idle
[tid: 140056751183616]	run: hello!
[tid: 140056759576320]	idle
[tid: 140056759576320]	run: hello!
[tid: 140056751183616]	idle
[tid: 140056751183616]	run: hello!
[tid: 140056734398208]	idle
2 seconds later...
There are still 0 tasks need to handle
Now I will end all threads!
2 seconds later...
[tid: 140056734398208]	exit
[tid: 140056767969024]	idle
[tid: 140056767969024]	exit
[tid: 140056759576320]	idle
[tid: 140056759576320]	exit
[tid: 140056751183616]	idle
[tid: 140056751183616]	exit
[tid: 140056742790912]	idle
[tid: 140056742790912]	exit
2 seconds later...
There are still 0 tasks need to handle
Thread pool clear, exit.
 */