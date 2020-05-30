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
  

//jor p67, ???????val???
void rmNode(Node **pHead, int val)
{
	
	if(!pHead || !(*pHead))
		return;

	Node preHead;
	Node *p = &preHead, *tmp;
	p->next = *pHead;

	while(p && p->next)
	{
		if(p->next->val == val)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
			p = p->next;
	}
	*pHead = preHead.next;
}


void _test_rmNode()
{   
	Node *h = new Node();

	h->val = 1;
	h->next = new Node();
	h->next->val = 2;
	h->next->next = NULL;
	
//	Node *nh = NULL;
//	Node **ph = &nh;
	
	Node **ph = &h;
	rmNode(ph, 1);
	cout << (*ph)->val << endl;	
}   



int main()
{

	return 0;
}
