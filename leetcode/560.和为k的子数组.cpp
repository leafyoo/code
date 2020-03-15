// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if( !n ) return 0;

        int res = 0;
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        for( int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + nums[i-1];

        for( int i = 1; i <= n; ++i)
        {
            for( int j = 0; j < i; ++j)
            {
                if( sum[i] - sum[j] == k)
                    ++res;
            }
        }
        
        return res;
    }
};
// @lc code=end
/* 
fish：
前缀和的思想
SUM[0-0]， SUM[0-1]， SUM[0-2]，SUM[0-3]，
中间的连续和就是上面的两两相减

 */



/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.59%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 40.8K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */
