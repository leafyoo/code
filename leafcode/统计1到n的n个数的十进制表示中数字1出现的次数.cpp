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


//jor p191，1到n的n个数的十进制表示中数字1出现的次数
int countOf1Betweent1AndN(int num)
{
	if(num < 1)
		return 0;
	int res = 0, tmp;
	for(int i = 1; i <= num; ++i)				//不要i < num+1,以防num+1溢出
	{
		for(tmp = i; tmp > 0; tmp /= 10 )
		{
			if(tmp%10 == 1)
				++res;
		}
	}
	return res;
}
void _test_countOf1Betweent1AndN()
{
	cout << countOf1Betweent1AndN(1)<< endl;
	cout << countOf1Betweent1AndN(19)<< endl;
	cout << countOf1Betweent1AndN(22)<< endl;
}

int main()
{

	return 0;
}
