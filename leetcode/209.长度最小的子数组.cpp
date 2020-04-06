// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() < 1) return 0;                   //错误：这里没判空，就导致提交未通过。

        int imin = INT_MAX;
        int b = 0, e = 0, sum = nums[0];
        while( b <= e && e < nums.size() && b < nums.size() )
        {
            if(nums[b] >= s || nums[e] >= s)
                return 1;
            if(sum < s )
            {
                if( e+1 > nums.size() - 1) break;           //错误：这里要再次判断e的范围
                ++e;
                sum += nums[e];
            }
            else
            {
                imin = min(imin, e - b + 1 );
                sum -= nums[b];
                ++b;
            }
        }

        return imin == INT_MAX ? 0 : imin;                    //错误：上面while结束，未必就是找到了
    }
};
// @lc code=end

/* fish：滑动窗口 法

 */

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.21%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    27.9K
 * Total Submissions: 67.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */