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
using namespace std;


#include <stdlib.h>
#include <time.h>
  
/* 
所以判断浮点数是否等于0：

要判断一个单精度浮点数是否等于0：if(fabs(f_float) <= 1e-6);
要判断一个双精度浮点数是否等于0：if(fabs(d_double) <= 1e-15);
所以判断两个浮点数相等：

要判断两个单精度浮点数是否相等：if(fabs(f1_float - f2_float) <= 1e-6);
要判断两个双精度浮点数是否相等：if(fabs(d1_double - d2_double) <= 1e-15);
————————————————
版权声明：本文为CSDN博主「涔曦」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xiaotian2516/java/article/details/93210636
 */
//jor p107, 求数值的整数次方，不必考虑大数问题
double exp(double base, int n)
{
	// if(base > -1e-15 && base < 1e-15)
	if(base == 0)
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
	cout << exp(-0.000001, 2) << endl;
//	cout << exp(2.1, 3);
	cout << exp(2.1, -3) << endl;
}

int main()
{
	_test_exp();
	return 0;
}
