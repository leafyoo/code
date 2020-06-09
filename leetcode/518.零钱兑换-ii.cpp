// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount+1, 0);        //错误：这里应该是 amount
        dp[0] = 1;

        //这里的内外层循环和 [322] 题不一样
        for(int i = 0; i < coins.size(); ++i)   //遍历硬币面值
        {
            //所有金额均小于 coin 美分不会受到 coin 美分硬币的影响。 因此对于 amount = 0 、1 的结果没有变化。
            for( int j = coins[i]; j <= amount; ++j)    //遍历金额        
            {
                dp[j] += dp[ j - coins[i] ];
            }
        }

        return dp[amount];
    }
};
// @lc code=end

/* 
fish
遍历所有硬币面值：
对于每个硬币，我们将从金额 0 遍历到 amount：
对于每个 x，计算组合数：dp[x] += dp[x - coin]。

https://leetcode-cn.com/problems/coin-change-2/solution/ling-qian-dui-huan-ii-by-leetcode/
 */

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode-cn.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (48.91%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 20.9K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: amount = 5, coins = [1, 2, 5]
 * 输出: 4
 * 解释: 有四种方式可以凑成总金额:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * 示例 2:
 * 
 * 输入: amount = 3, coins = [2]
 * 输出: 0
 * 解释: 只用面额2的硬币不能凑成总金额3。
 * 
 * 
 * 示例 3:
 * 
 * 输入: amount = 10, coins = [10] 
 * 输出: 1
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 你可以假设：
 * 
 * 
 * 0 <= amount (总金额) <= 5000
 * 1 <= coin (硬币面额) <= 5000
 * 硬币种类不超过 500 种
 * 结果符合 32 位符号整数
 * 
 * 
 */

