// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty() || amount <= 0) return 0;              //非法值判断永不忘！！！不要管已知题干告诉的信息

        vector<int> dp(amount+1, amount+1);                     //错误：这里用了dp(amount+1, INT_MAX); 导致下文溢出了
        sort(coins.begin(), coins.end(), less<int>() );

        dp[0] = 0;
        for( int i = 1; i <= amount; ++i)
        {
            for( int j = 0; j < coins.size(); ++j)
            {
                if(i- coins[j] >= 0)
                    dp[i] = min(dp[i], dp[ i- coins[j] ] + 1);
                else
                    break;
            }
        }

        return dp[amount] == amount+1 ? -1 :  dp[amount] ;          //错误：审。 审题，返回-1
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.51%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 115.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */
