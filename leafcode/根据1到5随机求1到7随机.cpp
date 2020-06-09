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


#include <stdlib.h>
#include <time.h>
//CIG p392, 根据1到5随机求1到7随机。
int rand1to5()
{
	srand(time(NULL));//设置随机数种子。
	return rand()%5 + 1;	//[0-4] + 1
}
int rand1to7()
{
	int num = 0;
	do
	{
		num = ( rand1to5()-1 )*5 + (rand1to5()-1);	//前半部分生成 0 5 10 15 。。
	}while(num > 20);		//因为3*7=21，所以这里可以是20，是num > 7也可以的下面要改逻辑
	return num % 7 + 1;
}
void __test_rand1to7()
{
	cout << rand1to7();
}



int main()
{

	return 0;
}
