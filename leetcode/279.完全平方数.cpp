// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if(n < 2) return 1;
        vector<int> dp(n+1, 0);

        for( int i = 1; i <= n; ++i)
            dp[i] = i;
        
        //位置关系：  [0 ..... j ............. i]
        for( int i = 2; i <= n; ++i)
        {
            for( int j = 1; i - j*j >= 0 ; ++j)             //错误：这里 >= ，少了 =， 因为i - j*j == 0则只需要1个平方数
                dp[i] = min( dp[i], dp[i - j*j]+1 );
        }
        
        return dp[n];
    }
};
// @lc code=end
/* fish
https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/
 */


/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (53.61%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    39.5K
 * Total Submissions: 72.9K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
