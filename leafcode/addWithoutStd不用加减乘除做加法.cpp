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


//jor p254，不用加减乘除做加法
int addWithoutStd(int n, int m)
{
	int sum = 0,carry = 0;
	
	do
	{
		sum = n ^ m;
		carry = (n & m)<<1;
		
		n = sum;					//进一步赋值，进入下一循环继续计算
		m = carry;
	}while(m);
	
	return n;
}
void _test_addWithoutStd()
{
//	cout << addWithoutStd(2,3);
	cout << addWithoutStd(11,3);
}


int main()
{

	return 0;
}
