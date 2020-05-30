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



//MS p310， 求n阶乘后有多少个0， 0! = 1
int tenInJiecheng(int num)
{
	if(num < 1)
		return 0;
	int count = 0;
	for(int i = 1; i <= num; ++i)
	{
		for(int j = i; j>0 && j % 5 == 0; j /= 5)
		{
			++count;
		}
	}
	return count;
}
void _test_tenInJiecheng()
{
	cout << tenInJiecheng(0);
}


int main()
{

	return 0;
}
