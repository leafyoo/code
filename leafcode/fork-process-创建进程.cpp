#include <iostream>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <errno.h>  
#include <unistd.h> 
#include <sys/wait.h>

#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

//一个父进程，创建多个子进程
int func()
{
    int const child = 10;
	pid_t pid;
    
    for (int i = 0; i < child; ++i)//创建子进程个数
    {
        pid=fork()
    	if (pid==0)//判断是否为子进程
    	{
    		printf("子进程 %d：%d\n",i+1,getpid());
    		return 0;//结束子进程
    	}
        else if(pid < 0)
        {
    		printf("fork error! \n" );
    		return -1;//结束子进程
        }
        else
        {
            printf("这里是父进程，刚才创建了子进程： %d ! \n" ,pid);
        }

    	// waitpid(pid,NULL,WUNTRACED);//等待当前子进程结束
    }

    for (int i = 0; i < child; ++i)//创建子进程个数
    {
        int pid = wait(NULL);
        cout << "进程：" << pid << " exit" << endl;
    }    

    printf("\n");
    printf("父进程:%d\n",getpid());
 
	return 0;
}


int main(int argc, char ** argv)
{
    // cout << "arg1:" << argv[1] <<endl;
    // cout << "arg2:" << argv[2] <<endl;
    // cout << endl;
    // cout << "res:"<< endl;
    // cout << func(string( argv[1] ), string( argv[2]));

    func();

    return 0;
}

/* 
$ ./a.exe
子进程1：1931
子进程2：1932
子进程3：1933
子进程4：1934
子进程5：1935
子进程6：1936
子进程7：1937
子进程8：1938
子进程9：1939
子进程10：1940
进程：1931 exit
进程：1932 exit
进程：1939 exit
进程：1938 exit
进程：1937 exit
进程：1936 exit
进程：1935 exit
进程：1934 exit
进程：1933 exit
进程：1940 exit

父进程:1930
 */




