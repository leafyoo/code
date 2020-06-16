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


//cig p13, 借助一个栈来排序另一个栈
//先问栈顶是最大还是最小
void sortStackWithOneStack(stack<int> &st )
{
	if(st.size() < 2)
		return;

	stack<int> st2;  //栈底元素最小
	while(!st.empty())
	{
		int cur = st.top();
		st.pop();

		while(!st2.empty() && st2.top() > cur)		//help只要小的，腾笼
		{
			int tmp = st2.top();
			st2.pop();
			st.push(tmp);		//每次经过这样置换，st里的元素从底到顶逐渐变成有序的了
		}

		st2.push(cur);		//只接收更小的元素
	}

	while(!st2.empty())
	{
		st.push(st2.top());
		st2.pop();
	}
}
void _test_sortStackWithOneStack()
{
	int a[] = {1,2,4,3};
	stack<int> st;
	arrToStack(a, sizeof(a)/sizeof(a[0]), st);
	sortStackWithOneStack(st);
	printStack(st);
}



int main()
{

	return 0;
}
