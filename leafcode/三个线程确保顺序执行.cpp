#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <stdexcept>
#include "mylib.hpp"
using namespace std;


//与原书设计有差异，需进一步确认?
//ms p304, 同一个foo实例会被传入3个不同的线程，3个线程分别有3个不同的任务a，b，c
//设计一种机制，确保a在b前，b在c前执行
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> 
class ThreadRunInOrder
{
	public:
		ThreadRunInOrder()
		{
			sem_init(&sem1, 1, 0);//参数value 为信号量的初始值。参数pshared用于说明信号量的共享范围，如果pshared 为0，那么该信号量只能由初始化这个信号量的进程中的线程使用，如果pshared 非零，任何可以访问到这个信号量的进程都可以使用这个信号量。
			sem_init(&sem2, 1, 0);
		}
		void* one(void*)
		{
			cout << "1 beg" << endl;
			sleep(1);
			cout << "1 end" << endl;

			sem_post(&sem1);
			return NULL;
		}
		void* two(void*)
		{
			sem_wait(&sem1);
			sem_post(&sem1);

			cout << "2 beg" << endl;
			sleep(1);
			cout << "2 end" << endl;

			sem_post(&sem2);
			return NULL;
		}
		void* third(void*)
		{
			sem_wait(&sem2);
			sem_post(&sem2);

			cout << "3 beg" << endl;
			sleep(1);
			cout << "3 end" << endl;

			return NULL;
		}
		~ThreadRunInOrder()
		{
			sem_destroy(&sem1);
			sem_destroy(&sem2);
		}
	private:
		sem_t sem1, sem2 ;
};

ThreadRunInOrder c;
void _test_ThreadRunInOrder()
{
	pthread_t t1, t2,t3;


	cout << "t1" << endl;
	pthread_create(&t1, NULL, (void* (*)(void*))c.one(NULL), NULL);

	cout << "t2" << endl;
	pthread_create(&t2, NULL, (void* (*)(void*))c.two(NULL), NULL);

	cout << "t3" << endl;
	pthread_create(&t3, NULL, (void* (*)(void*))c.third(NULL), NULL);

	sleep(5);
	
	// pthead_join(t1, NULL);
	// pthead_join(t2, NULL);
	// pthead_join(t3, NULL);
}
/*
需要有sleep(5);,不然主线程提前挂掉，如下报错
fish@Colin /cygdrive/d/cc/alg
$ g++ jianZhiOr.cpp ;./a
1
*** starting debugger for pid 4856, tid 5200
*/

int main()
{

	return 0;
}
