
// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        for( int i = q.size(); i > 1 ; --i)         //思路：每次pop时，把所有的头部的值pop一遍，再塞到尾部，相当于一次大回旋
        {
            int t = q.front();
            q.pop();
            q.push( t );
        }

        if(q.empty())
            throw runtime_error("empty"); 

        int ret = q.front();
        if(!q.empty())
            q.pop();

        return ret;
    }
    
    /** Get the top element. */
    int top() {
        if(q.empty())
            throw runtime_error("empty"); 
                    
        return q.back();            //这里注意，不是 q.top()!!  而是  q.back() ！！
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/* fish

时间复杂度：压入 - O(1)， 弹出 - O(n)
注意：空间复杂度：O(1)  ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！



方法一 （两个队列， 压入 -O(1)O(1)，  弹出 - O(n)O(n)）
方法二 （两个队列， 压入 - O(n)O(n)， 弹出 - O(1)O(1)）
方法三 （一个队列， 压入 - O(1)， 弹出 - O(n)

 */


/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (62.23%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    39.2K
 * Total Submissions: 61.4K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */
