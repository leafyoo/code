// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) 
            return 0;

        int imax = nums[0] , imin = nums[0], res = nums[0];
        
        //错误：这里不能从0开始，虽然内部不会越界，但是存在重复计算
        for( int i = 1; i < nums.size(); ++i)                       
        {
            //错误：这里没有用 imaxLast、iminLast，则会导致计算imin时，imax已近被改变了。
            int imaxLast = imax, iminLast = imin;                   

            imax = max(nums[i], max(iminLast*nums[i], imaxLast*nums[i]));
            imin = min(nums[i], min(iminLast*nums[i], imaxLast*nums[i]));

            res = max(imax, res);
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

