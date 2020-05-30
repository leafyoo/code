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



//" " ---> "%20"
char *replaceBlank(char *s)
{
	if(!s || !(*s))
		return s;
	char *h = s;
	int n = 0;
	for(; *h; ++h)
	{
		if(*h == ' ')
			++n;
	}
	for(; n > 0; --h)
	{
		if(*h == ' ')
		{
			*(h + 2*n) = '0';
			*(h + 2*n - 1) = '2';
			*(h + 2*n - 2) = '%';
			--n;
		}
		else
		{
			*(h + 2*n) = *h;
		}
	}
	return s;
}
/*
头、尾空格;
中间多个空格；
" "
*/

void _test_replaceBlank()
{
	char a[20];
	strcpy(a, " a  b c ");
//	strcpy(a, " ");
	cout << replaceBlank(a);
	
}


int main()
{

	return 0;
}
