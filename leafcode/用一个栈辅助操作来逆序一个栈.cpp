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


//CIG P8，仅用递归函数、栈操作来逆序一个栈
//递归，把栈看作两部分， 只有两个元素，那弹出栈顶只是为了使得栈底元素露出来，所以之后还得push进去
int getLastElement(stack<int> &s)
{
    int result = s.top();
    s.pop();
    if (s.empty()) 
		return result;    				// 如果只有一个元素即为栈底的元素 返回  
    else 
	{
        int last = getLastElement(s);   // 得到栈底元素  
        s.push(result);   				// 并栈顶元素压栈  
        return last;
    }
}
void reverseStack(stack<int> &s) 
{
    if (s.empty()) 
		return;    						// 递归结束的终止条件  
    int i = getLastElement(s);   		// 得到栈底的最后一个元素 剩下元素依旧  
    reverseStack(s);    				// reverse 剩下  
    s.push(i);  						// 将i push进去  

}
void _test_reverseStack()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	reverseStack(st);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
}

int main()
{

	return 0;
}
