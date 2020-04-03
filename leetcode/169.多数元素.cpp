// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if(nums.empty()) return -1;
        int res = nums[0], cnt = 1;

        for( int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == res)    
                ++cnt;
            else
            {
                --cnt;
                if(cnt < 1)
                {
                    res = nums[i];
                    cnt = 1;
                }
            }
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (62.76%)
 * Likes:    531
 * Dislikes: 0
 * Total Accepted:    148.7K
 * Total Submissions: 236.8K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

