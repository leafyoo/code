// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        
        int dayCnt = prices.size(), statCnt = 2;   
        
        //这里要明白：dp代表的是 因为投资股票而引起的收益，所以并不是一个人的所有财富什么的！！
        //那这样的话，当然第一天的初始收益就很合理了
        vector<vector< int> > dp(dayCnt, vector<int>(statCnt, 0) );
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;        //第一天，就买入一笔股票，自己贴了很多钱进去，当然利润是负值

        for( int day = 1; day < dayCnt; ++day)   
        {
            //今天无股票
            dp[day][0] = max( dp[day-1][0], dp[day-1][1] + prices[day] );      

            //今天有股票
            //解释：-fee 相当于买入股票的价格升高了。在第一个式子里减也是一样的，相当于卖出股票的价格减小了。参见下面的另一个版本
            dp[day][1] = max( dp[day-1][1], dp[day-1][0] - prices[day] - fee);  //为什么是求max？因为对比的是昨天就买划算 还是 等到今天再买划算
        }

        return dp[dayCnt-1][0];
    }
};
// @lc code=end
/* fish：
股票交易时，现实中，买入卖出都会收费，这里综合成一笔，所以在买入或者卖出时计费都可以。
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-2/
*/

/*

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        
        int dayCnt = prices.size(), statCnt = 2;    //actCnt允许的最大交易次数，本题为2

        vector<vector< int> > dp(dayCnt, vector<int>(statCnt, 0) );
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for( int day = 1; day < dayCnt; ++day)   
        {
            //今天无股票
            dp[day][0] = max( dp[day-1][0], dp[day-1][1] + prices[day] - fee);      

            //今天有股票
            //解释：-fee 相当于买入股票的价格升高了。在第一个式子里减也是一样的，相当于卖出股票的价格减小了。
            dp[day][1] = max( dp[day-1][1], dp[day-1][0] - prices[day] );  
        }

        return dp[dayCnt-1][0];
    }
};
 */


/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (63.46%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 24.2K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
 * 
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 
 * 返回获得利润的最大值。
 * 
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 * 
 * 示例 1:
 * 
 * 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * 输出: 8
 * 解释: 能够达到的最大利润:  
 * 在此处买入 prices[0] = 1
 * 在此处卖出 prices[3] = 8
 * 在此处买入 prices[4] = 4
 * 在此处卖出 prices[5] = 9
 * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * 注意:
 * 
 * 
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 * 
 * 
 */

