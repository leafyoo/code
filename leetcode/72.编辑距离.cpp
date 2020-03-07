// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));

        for( int i = 0; i <= n1; ++i)   //即word2位空字符串时
            dp[i][0] = i;
        for( int i = 0; i <= n2; ++i)   //即word1位空字符串时
            dp[0][i] = i;
        
        for( int i = 1; i <= n1; ++i)
        {
            for( int j = 1; j <= n2; ++j)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min( dp[i-1][j-1]+1,         /* 替换 */
                                    min(dp[i][j-1]+1,       /* 插入 */
                                        dp[i-1][j]+1 ) );   /* 删除 */
                }
            }
        }

        return dp[n1][n2];
    }
};
// @lc code=end

/*
fish:

 题解： https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-mian-shi-ti-xiang-jie-by-labuladong/ 

*/


/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (56.28%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 53.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 示例 1:
 * 
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2:
 * 
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */
