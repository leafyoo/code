// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int> > dp(row+1, vector<int>(col+1, 0));     //这里多申请 +1的好处：下文用到 i-1，不用对矩形边特殊处理

        int maxLen = 0;
        for( int i = 1; i <= row; ++i)
        {
            for( int j = 1; j <= col; ++j)
            {
                if( matrix[i-1][j-1] == '1')                        //错误：这里很迷惑，应该为i-1。注意区分 matrix和dp的边界。
                {
                    dp[i][j] = min(dp[i-1][j-1] , min( dp[i-1][j], dp[i][j-1]) ) + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen * maxLen;
    }
};
// @lc code=end
/*
fish: 
1、dp一类的问题，到底要不要申请+1的大小？ 如上，这个申请了+1大小的内存，这样避免了对矩阵边的处理，因为边默认是0
2、dp(i,j) 表示的是以(i-1,j-1)为右下角顶点的、由 1 组成的最大正方形的边长；
*/


/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (38.94%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 58.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
