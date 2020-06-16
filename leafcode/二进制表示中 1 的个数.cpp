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
  

//jor p95, 数的二进制表示中 1 的个数
//注意:左移的话负数会有死循环
int bit_count(int n)
{
	unsigned int flag = 1;
	int count = 0;

	while(flag)
	{
		if(n & flag)
			++count;
		flag <<= 1;
	}

	return count;
}
void _test_bit_count()
{
	cout << bit_count(0);
}


int main()
{
	return 0;
}
