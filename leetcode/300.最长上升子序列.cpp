// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        vector<int> dp(nums.size(), 1);         //直接都初始化为1

        //找出以每一个i为尾巴的lis
        for( int i = 1; i < nums.size(); ++i)
        {
            for( int j = 0; j < i; ++j)  //通过比较来更新 以i为尾巴的lis
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
/*
fish: dp[i] :表示以i为最后一个元素的上升子序列的长度


*/


/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.97%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 116.2K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */
