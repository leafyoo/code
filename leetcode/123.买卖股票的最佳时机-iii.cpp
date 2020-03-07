// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size();
        const int maxAction = 2, statusNum = 2;
        // int dp[n+1][maxAction+1][statusNum] = {0};          //技巧：三维数组，初始化方法。 另外，要注意，如果量很大，要用vector，避免栈溢出

        vector<vector<vector< int> > > dp(n+1,   vector<vector<int> >(maxAction+1,  vector<int>(statusNum, 0)) );

        for( int i = 0; i <= maxAction; ++i)
        {
            dp[0][i][0] = 0;
            dp[0][i][1] = INT_MIN;
        }

        for( int i = 1; i <= n; ++i)
        {
            for( int j = 1; j <= maxAction; ++j)
            {   //prices[i-1] 表示今天的股价

                // dp[i-1][j][1] + prices[i-1]  昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了.如果 buy，就要从利润中减去 prices[i]，如果 sell，就要给利润增加 prices[i]。
                dp[i][j][0] = max( dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);      

                //昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
                dp[i][j][1] = max( dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
            }
        }

        return dp[n][maxAction][0];
    }
};
// @lc code=end

/* 
fish:

题解：
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
              max(   选择 rest  ,           选择 sell      )

解释：今天我没有持有股票，有两种可能：
要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
              max(   选择 rest  ,           选择 buy         )

解释：今天我持有着股票，有两种可能：
要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
这个解释应该很清楚了，如果 buy，就要从利润中减去 prices[i]，如果 sell，就要给利润增加 prices[i]。今天的最大利润就是这两种可能选择中较大的那个。而且注意 k 的限制，我们在选择 buy 的时候，把 k 减小了 1，很好理解吧，当然你也可以在 sell 的时候减 1，一样的。

作者：labuladong
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/


 */


/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (41.06%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    23.4K
 * Total Submissions: 56.4K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [3,3,5,0,0,3,1,4]
 * 输出: 6
 * 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。   
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,6,4,3,1] 
 * 输出: 0 
 * 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
 * 
 */