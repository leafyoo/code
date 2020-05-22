// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        if(n == 1) return nums[0];

        int imax = 1, imin = 1, res = nums[0];              //错误：这里定义为long long，导致和max(int, int)函数不匹配了
        for( int i = 0; i < n; ++i)
        {
            if(nums[i] > 0)
            {
                imax = max(imax*nums[i], nums[i]);          //因为是连续子数组，所以，这里是: , nums[i]);
                imin = min(imin*nums[i], nums[i]);
            }
            else
            {
                int imaxOld = imax;                         //错误：这里要备份上一次的imax，避免被覆盖
                imax = max(imin*nums[i], nums[i]);
                imin = min(imaxOld*nums[i], nums[i]);
            }

            res = max(res, imax);                           //注意imax不一定是全局的max
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    36.5K
 * Total Submissions: 97.7K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

