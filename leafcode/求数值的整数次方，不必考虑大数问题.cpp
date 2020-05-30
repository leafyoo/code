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
  

//jor p107, 求数值的整数次方，不必考虑大数问题
double exp(double base, int n)
{
	if(base > -0.0000001 && base < 0.0000001)
		return 0;							//这里0和0.0有区别吗?
	if(n == 0 || base == 1)
		return 1;
	if(base == -1)
		return n%2 ? -1 : 1;
	
	double res = 1;
	int nNew = n;
	if(n < 0)
	{
		nNew = -n;
	}
	for(int i = 0; i < nNew; ++i)
	{
		res *= base;
	}
	if(n < 0)
		res = 1/res;				//虽然判断0需要用0.0000001,但是分母下可以小数点后很多很多位。已测试
	return res;
}
void _test_exp()
{
//	cout << exp(-0.000000001, 3);
//	cout << exp(2.1, 3);
	cout << exp(2.1, -3);
}

int main()
{

	return 0;
}
