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

//jor p203, 求第一个只出现一次的字符，如输入"abaccd"则输出'b'
char findFirstSingle(const char * s)		//这里要const，不然: 警告：不建议使用从字符串常量到‘char*’的转换 
{
	if(!s || !(*s))
		return '\0';

	int hash[256] = {0};		//【leaf】无论字符串多长，最多永远只可能有256个字符。
	const char *p = s;
	for(; *p; ++p)
	{
		++hash[(int)(*p)];
	}
	
	for(p = s; *p; ++p)						//要从s头部开始遍历，而不是从0~255
	{
		if(hash[(int)(*p)] == 1)
			return *p;
	}

	return '\0';
}
void _test_findFirstSingle()
{
	cout << findFirstSingle("abbacdd");
}


int main()
{

	return 0;
}
