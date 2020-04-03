// @lc code=start
class KthLargest {
public:
    int mK;                         //技巧：注意类成员变量的区分，可以用m前缀
    multiset<int> ms;

    KthLargest(int k, vector<int>& nums) {
        this->mK = k;
        for( int i = 0; i < nums.size(); ++i)
        {
            ms.insert(nums[i]);
            if(ms.size() > mK)
                ms.erase( ms.begin());      //注意：第k大，就是降序排列的第k个元素，要删除小的值
        }
    }
    
    int add(int val) {
        ms.insert(val);
        if(ms.size() > mK)
            ms.erase( ms.begin());
        return *(ms.begin());           //错误：返回值：迭代器要解引用
    }
};

class KthLargest_pq {
public:
    int mK;                         //技巧：注意类成员变量的区分，可以用m前缀
    priority_queue<int, vector<int>, greater<int> > pq;

    KthLargest_pq(int k, vector<int>& nums) {   //错误：这里是构造函数，要和类同名，不然编译不通过，KthLargest_pq
        this->mK = k;
        for( int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
            if(pq.size() > mK)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > mK)
            pq.pop();
        return pq.top();           //错误：返回值：迭代器要解引用
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (42.82%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 37.7K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n' +
  '[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
 * 
 * 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用
 * KthLargest.add，返回当前数据流中第K大的元素。
 * 
 * 示例:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * 说明: 
 * 你可以假设 nums 的长度≥ k-1 且k ≥ 1。
 * 
 */

