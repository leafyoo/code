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

//jor p119,调整数组使所有奇数位于前半部分
void reorderOddEven(int *arr, int len)
{
	if(!arr || len < 2)	
		return;
	int beg = 0, end = len - 1, tmp;
	while(beg < end)
	{
		while(beg < end && (arr[beg] & 0x1) != 0)		//奇数偶数判断:用&
			++beg;
		while(beg < end && (arr[end] & 0x1) == 0)
			--end;										//其他数字求余不可以这样代替!!	
		if(beg < end)									//if((a[beg] % 2 == 0)  && (a[end] % 2 != 0))
		{
			tmp = arr[beg];
			arr[beg] = arr[end];
			arr[end] = tmp;
		}
	}
}

void _test_reorderOddEven()
{
//	int arr[] = {0};
//	reorderOddEven(arr, 1);
//	cout << arr[0];
	
//	int arr[] = {0,1};
//	reorderOddEven(arr, 2);
//	cout << arr[0] << arr[1];

//	int arr[] = {0,1,2};
//	reorderOddEven(arr, 3);
//	cout << arr[0] << arr[1] << arr[2];

	int arr[] = {0,1,2,3};
	reorderOddEven(arr, 4);
	cout << arr[0] << arr[1] << arr[2] << arr[3];
}


int main()
{

	return 0;
}