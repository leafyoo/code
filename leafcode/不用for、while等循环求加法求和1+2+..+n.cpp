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


//jor p250， 不用for、while等循环求1+2+..+n
class sum1ToN
{
	public:
		sum1ToN()
		{
			++n;
			sum += n;
		}
		~sum1ToN(){}
		static void init()
		{
			n = 0;
			sum = 0;
		}
		static int getSum()
		{
			return sum;
		}
	private:
		static int n;
		static int sum;
};
int sum1ToN::n = 0;						//只可以在全局区域内定义
int sum1ToN::sum = 0;
void _test_sum1ToN()
{
	//int sum1ToN::n = 0;				//错误，在这里不可以访问
	sum1ToN::init();
	int n = 5;
	sum1ToN *p = new sum1ToN[n];		//当然可以在栈上定义，但是如果n很大，占用栈空间
	cout << sum1ToN::getSum();
	delete []p;
	p = NULL;
}


int main()
{

	return 0;
}
