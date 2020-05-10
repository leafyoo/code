// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return {};

        vector<int> next(n, -1);
        stack<int> stk;         //存储到当前i为止，从左到右看到的最大的数
        
        for( int i = 2 * n - 1; i >= 0; --i)
        {
            int tmp = -1;
            while( !stk.empty() && stk.top() <= nums[i % n])        //错误：这里是 <=，因为相等时不是大于，也要pop出来，
                stk.pop();
            if( !stk.empty() && stk.top() > nums[i % n])
                tmp = stk.top();
            
            stk.push( nums[i % n] );
            next[i % n] = tmp;
        }

        return next;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode-cn.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (53.44%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 28.4K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
 * 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 注意: 输入数组的长度不会超过 10000。
 * 
 */

