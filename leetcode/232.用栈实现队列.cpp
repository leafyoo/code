// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = peek();           //这里尽量复用下面的代码
        if(!st2.empty())
            st2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty())
        {
            while( !st1.empty() )
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        //这里要判断并抛出异常，否则，st2为空，返回一个值，调用侧该怎么理解。
        if(st2.empty())
            throw new RuntimeException("queue is empty");       //【知识点】 抛异常
        else
            return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st2.empty() && st1.empty();
    }

    stack<int> st1;
    stack<int> st2;

};


//线程安全版本，支持并发。
/* 考虑：
多线程下面临的问题，假如这个对象是进程级别的，那进程内部的线程都可以访问这一个数据结构，
线程A刚访问一半，
线程B又进入访问，
线程A再写操作，
线程B再写操作，
最终数据会乱掉的。。。
 */
class Que {
public:
    Que() {}
    
    void push(int x) 
    {
        wrlock();

        st1.push(x);
        
        unlock();
    }
    
    int pop() 
    {
        wrlock();

        int ret = _peek();       //不能只对peek内部单独加锁，不然如果某个线程连续pop两次，返回的值可能是一样的。因为peek这里的锁释放后就可能切换到其他的线程去。
        if(!st2.empty())
            st2.pop();
            
        unlock();
        return ret;
    }

    int peek()          //可供外部调用
    {
        int res = 0;

        wrlock();
        res = _peek();
        unlock();

        return res;
    }

    int _peek()     //内部无锁，专门给内部使用的函数
    {
        int res = 0;
        if(st2.empty())
        {
            while( !st1.empty() )
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        res = st2.top();
        return res;
    }
    
    bool empty() 
    {
        rlock();    

        return st2.empty() && st1.empty();
        
        unlock();  
    }

    stack<int> st1;
    stack<int> st2;

    rwlock_t m_lock;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 *
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (62.79%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    34.4K
 * Total Submissions: 54.4K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用栈实现队列的下列操作：
 * 
 * 
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 * 
 * 
 * 示例:
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 * 
 * 说明:
 * 
 * 
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 * 
 * 
 */

