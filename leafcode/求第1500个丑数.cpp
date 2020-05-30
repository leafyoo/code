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



//jor p199，丑数，即:只含因子2、3、5的数，求第1500个丑数
bool isUgly(int n)
{
	while(n % 2 == 0)
		n /= 2;
	while(n % 3 == 0)
		n /= 3;
	while(n % 5 == 0)
		n /= 5;
	return n == 1 ;
}
int findNthUgly(int n)
{
	if(n < 1)
	{
		return 0;
	}
	int i = 1;						//死循环:int i = 0;
	for(; n > 0; ++i)
	{
		if(isUgly(i))
			--n;
	}
	return --i;	
}
void _test_findNthUgly()
{
	cout << findNthUgly(7);
}

int main()
{

	return 0;
}
