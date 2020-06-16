// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if(triangle.empty() || triangle[0].empty()) 
            return 0;

        int r = triangle.size();

        //错误：这里用了dp(r, vector<int>(col)); 其中col = triangle[0].size();，每一行大小是不同的！
        vector<vector<int> > dp(r, vector<int>(r, 0)); 

        dp[0][0] = triangle[0][0];
        for( int i = 1; i < r; ++i)
        {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        }
        for( int i = 1; i < r; ++i)
        {
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }

        for( int i = 1; i < r; ++i)
        {
            for( int j = 1; j < i; ++j)
            {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }

        return *min_element(dp[r - 1].begin(), dp[r - 1].end());
    }
};
// @lc code=end
/*
fish:
技巧： 上文中可以加入  std::cout << dp[i][0] << std::endl;    调试信息，提交之后在结果中会打印出来。

换个角度看triangle

     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]

  即：

  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]

*/


/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (63.65%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    41.3K
 * Total Submissions: 64.8K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */