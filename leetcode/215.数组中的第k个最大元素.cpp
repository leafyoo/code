// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;       //小根堆， greater<int>， 即：更大的才能进入堆
        
        for( int i = 0; i < nums.size(); ++i)
        {
            if(q.size() >= k)
            {
                if(nums[i] > q.top())
                {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            else
                q.push(nums[i]);
        }

        return q.top();
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.05%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    94K
 * Total Submissions: 152.4K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */
