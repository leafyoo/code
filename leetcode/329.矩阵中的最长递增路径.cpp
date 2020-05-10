// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        mCol = matrix[0].size();
        mRow = matrix.size();

        int res = 0;
        vector<vector<int>> cache(mRow, vector<int>(mCol, 0));

        for (int r = 0; r < mRow; r++)
            for (int c = 0; c < mCol; c++)
               res = max(res, dfs(matrix, r, c, cache));
               
        return res;
    }

private:
    int mCol, mRow;
    vector<vector<int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };      //注意： vector的创建技巧，定义时指定初始化

    //在搜索过程中，如果未计算过单元格的结果，我们会计算并将其缓存；否则，直接从缓存中获取之。
    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &cache)
    {
        if (cache[row][col] != 0) return cache[row][col];       //已经计算过了

        for (auto d : dir)
        {
            int r = row + d[0];
            int c = col + d[1];
            if (r >= 0 && r < mRow && c >= 0 && c < mCol 
            && matrix[row][col] > matrix[r][c] )            //如果节点 [row, col]处的值小于它的四个方向的值
                cache[row][col] = max( cache[row][col], dfs(matrix, r, c, cache));
        }

        return ++cache[row][col];
    }
};

// @lc code=end

/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (40.13%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 28.9K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 * 
 * 示例 1:
 * 
 * 输入: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2:
 * 
 * 输入: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 */