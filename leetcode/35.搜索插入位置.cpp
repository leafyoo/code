// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int b = 0, e = nums.size() - 1;
        while( b <= e )                                 
        {
            int m = (b+e)/2;
            if(target == nums[m]) 
                return m;
            
            if(target < nums[m]) 
                e = m-1;
            else
                b = m+1;
        }

        if(b >= 0 && b < nums.size() && target > nums[b]) 
            return b+1;     //错误：这里要判断b的合法性，因为上面一系列变动会导致b可能越界。

        return b;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.16%)
 * Likes:    433
 * Dislikes: 0
 * Total Accepted:    119.5K
 * Total Submissions: 264.3K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */
