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
  

//jor p68. 从尾到头遍历链表。或者用栈，压栈
void printFromEnd_digui(Node *p)
{
	if(!p)
		return;
	printFromEnd_digui(p->next);
	cout << p->val << endl;
}

void _test_printFromEnd_digui()
{
	Node *h = new Node();

	h->val = 2;
	h->next = new Node();
	h->next->val = 1;
	h->next->next = NULL;
	
	Node *nh = NULL;
	Node **ph = &nh;
	printFromEnd_digui(*ph);	

//	Node **ph = &h;
//	printFromEnd_digui(*ph);
}


int main()
{

	return 0;
}
