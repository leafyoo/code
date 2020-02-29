
// @lc code=start
class Solution_best {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        int imax = nums[0] , imin = nums[0], res = nums[0];
        for( int i = 1; i < nums.size(); ++i)                       //错误：这里不能从0开始，虽然内部不会越界，但是存在重复计算
        {
            int imaxLast = imax, iminLast = imin;                   //错误：这里没有用 imaxLast、iminLast，则会导致计算imin时，imax已近被改变了。

            imax = max(nums[i], max(iminLast*nums[i], imaxLast*nums[i]));
            imin = min(nums[i], min(iminLast*nums[i], imaxLast*nums[i]));

            res = max(imax, res);
        }

        return res;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        vector<int> dpMax(nums.size() );
        vector<int> dpMin(nums.size() );
        
        int res = nums[0];
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        for( int i = 1; i < nums.size(); ++i)
        {
            dpMax[i] = max( max(dpMin[i-1] * nums[i] , dpMax[i-1] * nums[i]), nums[i]);     //因为会出现负号，导致最大、最小反过来，这里就每次都考虑进来。
            dpMin[i] = min( min(dpMin[i-1] * nums[i] , dpMax[i-1] * nums[i]), nums[i]);
            res = max(res, dpMax[i]);
        }

        return res;           //不定义res变量，用下面这个stl算法也可以
        // return *max_element(dpMax.begin(), dpMax.end());           
    }
};

// @lc code=end
/*
fish:
1. 由于只使用一个dp数组，导致负数存在时，情况考虑很复杂，提交未通过：失败的代码见下文：

*/


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


/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<long long> dp(nums.size());
        dp[0] = nums[0];

        for( int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] < 0)
            {
                if ( dp[i-1] < 0)
                {
                    dp[i] = nums[i]*dp[i-1];
                    if ( i-2 >= 0 && dp[i-2] > 0 )
                    {
                        dp[i] *= dp[i-2];
                    }
                }
                else
                {
                    if ( i-2 >= 0 && dp[i-2] < 0 )
                    {
                        dp[i] = dp[i-2] * nums[i-1] * nums[i];
                    }    
                    else
                        dp[i] = nums[i];
                }
            }
            else
            {                                       //nums[i] >= 0
                if ( dp[i-1] <= 0 )
                {
                    dp[i] = nums[i];
                }    
                else
                    dp[i] = nums[i] * dp[i-1];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
*/