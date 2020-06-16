// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        if(S < -1000 || S > 1000 || nums.empty()) 
            return 0;

        int n = nums.size();
        
        //2001个
        vector<vector<int> > dp(n, vector<int>(2001, 0) );
        
        dp[0][nums[0] + 1000] = 1;          //这里+1000只是dp的偏移（因为数组下标不能为负数）。含义：前0个数组成和为nums[0]的方案的个数。
        dp[0][-nums[0] + 1000] = 1;
        if(nums[0] == 0) dp[0][nums[0] + 1000] = 2;

        for( int i = 1; i < n; ++i)
        {
            for( int j = -1000; j <= 1000; ++j)
            {
                if (dp[i-1][j + 1000] > 0) 
                {
                    dp[i][j + nums[i] + 1000] += dp[i-1][j + 1000];
                    dp[i][j - nums[i] + 1000] += dp[i-1][j + 1000];
                }
            }
        }

        return dp[n-1][S+1000];
    }
};

/*
// 可以转换0 1 背包问题

https://leetcode-cn.com/problems/target-sum/solution/c-dfshe-01bei-bao-by-bao-bao-ke-guai-liao/

*/

// @lc code=end

/*
fish:


方法二：动态规划
这道题也是一个常见的背包问题，我们可以用类似求解背包问题的方法来求出可能的方法数。

我们用 dp[i][j] 表示用数组中的前 i 个元素，组成和为 j 的方案数。考虑第 i 个数 nums[i]，它可以被添加 + 或 -，因此状态转移方程如下：

dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]

给上式的j加上偏移，就可以写成递推的形式：

dp[i][j + nums[i]] = dp[i - 1][j] + dp[i][j + nums[i]]
dp[i][j - nums[i]] = dp[i - 1][j] + dp[i][j - nums[i]]

即
dp[i][j + nums[i]] += dp[i - 1][j]
dp[i][j - nums[i]] += dp[i - 1][j]

由于数组中所有数的和不超过 1000，那么 j 的最小值可以达到 -1000。在很多语言中，是不允许数组的下标为负数的，因此我们需要给 dp[i][j] 的第二维预先增加 1000，即：

dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000]
dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000]

作者：LeetCode
链接：https://leetcode-cn.com/problems/target-sum/solution/mu-biao-he-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



*/

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.38%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 41.8K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 示例 1:
 * 
 * 输入: nums: [1, 1, 1, 1, 1], S: 3
 * 输出: 5
 * 解释: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 注意:
 * 
 * 
 * 数组非空，且长度不会超过20。
 * 初始的数组的和不会超过1000。
 * 保证返回的最终结果能被32位整数存下。
 * 
 * 
 */