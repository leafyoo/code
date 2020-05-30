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


//jor p256, 设计一个不能被继承的类，但是可以建多个对象
class cannotInherit
{
	public:
		static cannotInherit* getInstance()
		{
			return new cannotInherit();
		}
		static void deleteInstance(cannotInherit *p)
		{
			delete p;
		}
	private:
		cannotInherit(){}
		~cannotInherit(){}
};


int main()
{

	return 0;
}
