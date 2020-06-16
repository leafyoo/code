// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        if(m < 2 || n < 2) 
            return 1;
        vector<vector<int> > dp(n, vector<int>(m, 1));      //这里指定初值1，则下文可以避免循环处理边

        for( int i = 1; i < n; ++i)
        {
            for( int j = 1; j < m; ++j)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[n-1][m-1];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (58.87%)
 * Likes:    438
 * Dislikes: 0
 * Total Accepted:    74.4K
 * Total Submissions: 126K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 */