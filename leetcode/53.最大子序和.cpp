
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0, maxSum = -1 - 0x7fffffff;          // INT_MIN 这个宏在 limits.h 里
        for( int i = 0; i < nums.size(); ++i)
        {
            if ( sum <= 0 )sum = 0;

            sum += nums[i];
            maxSum = ( sum > maxSum || i == 0)? sum : maxSum; 
        }

        return maxSum;
    }
};
// @lc code=end

/*
错误1：和可能为负数，maxSum初值不能是0，要定义为最小的负值，也可以在这里规避：  maxSum = ( sum > maxSum || i == 0)? sum : maxSum; 

*/

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.15%)
 * Likes:    1630
 * Dislikes: 0
 * Total Accepted:    161.4K
 * Total Submissions: 327.8K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
