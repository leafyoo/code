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


//数组中两数相减求对大值，只能小角标者作为被减数。
/*
找到最大值找到最小值，然后相减即可。
1、如果是说，前面的减去后面的，差的最大值？
2、如果是说，后面的减去前面的，差的最大值？

这两个问题就不一样了。
基础的想法可以用暴力。但是有更好的方法。
针对1，从后往前遍历数组，记录遍历过的数组元素的最小值，用当前元素相减。
针对2，从前往后遍历数组，记录遍历过的数组元素的最小值，用当前元素相减。
*/
//http://www.cnblogs.com/hapjin/p/5402537.html
int maxValueOfSub(int *a, int  n)
{
	if(!a || n < 2)
		return 0;
	int min = a[0], maxValue = 0, sub;
	for(int i = 1; i < n; ++i)
	{
		sub = a[i] - min;					//用一个中间变量，减少计算量
		if(sub < 0)
			min = a[i];
		else
			maxValue = (sub > maxValue ? sub : maxValue);
	}
	return maxValue;
}

void __test_maxValueOfSub()
{
	int a[] = {2,4,2,1,5,7};
	cout << maxValueOfSub(a, 6);
}


int main()
{

	return 0;
}
