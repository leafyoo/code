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



//ms p128，list是否为回文
bool isListMirror(Node *h)
{
	if(!h || !(h->next))
		return true;
	
	Node *p1 = h, *p2 = h;
	stack<int> st;
	while(p2 && p2->next)
	{
		st.push(p1->val);
		p1 = p1->next;
		p2 = p2->next->next;
	}
	if(p2)
		p1 = p1->next;
	while(st.size() > 0)
	{
		if(st.top() != p1->val)
			return false;
		p1 = p1->next;
		st.pop();
	}
	return true;
}
void _test_isListMirror()
{
//	int a[] = {1,2,3,2,2};
//	Node *h = arrToList(a, 5);
	
//	int a[] = {1,2,2,1};
//	Node *h = arrToList(a, 4);

//	int a[] = {1};
//	Node *h = arrToList(a, 1);

	int a[] = {1,2};
	Node *h = arrToList(a, 2);

	cout << isListMirror(h);
}



int main()
{

	return 0;
}
