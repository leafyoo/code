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


//CIG P41，反转双链表
DNode *reverseDoubleList(DNode *h)
{
	if(!h || !h->next)
		return h;	
		
	DNode *pre = NULL, *next = NULL;
	while(h)
	{
		next = h->next;
		h->next = pre;
		h->pre = next;
		pre = h;
		h = next;
	}

	return pre;
}
void _test_reverseDoubleList()
{
//	int a[] = {1,2,3,4,5};
//	int a[] = {1,2,4,5};
	int a[] = {1,2,5};
//	int a[] = {1,2};

	DNode *h = arrToDList(a, sizeof(a)/sizeof(a[0]));
	printDList(reverseDoubleList(h));
}

int main()
{

	return 0;
}
