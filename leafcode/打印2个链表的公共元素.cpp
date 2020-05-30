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


//CIG P34，打印2个list的公共元素
//公共元素，并不是链表交叉
void printCommonValueOfTwoOrderedList(Node *h1, Node *h2)
{
	if(!h1 || !h2)
		return;
	while(h1 && h2)
	{
		if(h1->val < h2->val)
			h1 = h1->next;
		else if(h1->val > h2->val)
			h2 = h2->next;
		else
		{
			cout << h1->val << endl;
			h1 = h1->next;
			h2 = h2->next;
		}
	}
}
void _test_printCommonValueOfTwoOrderedList()
{
	int a[] = {1,2,4,6};
	int a1[] = {-3,2,4,5};
	printCommonValueOfTwoOrderedList(arrToList(a, 4), 
		arrToList(a1, 4));
}



int main()
{

	return 0;
}
