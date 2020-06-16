// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty() || grid[0].empty()) 
          return 0;
        int res = 0;

        int nr = grid.size();
        int nc = grid[0].size();
        vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        for( int i = 0; i < nr; ++i)
        {
          for( int j = 0; j < nc; ++j)
          {
            if(grid[i][j] == '1')           //遇到 ‘1’，则陷入，以其为根结点启动广度优先搜索。
            {
              ++res;
              grid[i][j] = '0';
              
              queue< pair<int, int> > q;
              q.push( {i, j} );

              while( !q.empty() )       //吸星大法
              {
                //遍历 4 个方向
                int row = (q.front()).first, col = (q.front()).second;
                q.pop();

                for( int i = 0; i < 4; ++i)
                {
                  int r = row + dir[i][0],  c = col + dir[i][1];
                  if(r >= 0 && r < nr && c >= 0 && c < nc && grid[r][c] == '1')
                  {
                    q.push( {r, c} );
                    grid[r][c] = '0';
                  }
                }
              }
            }
          }
        }

        return res;
    }
};
// @lc code=end

/* 
深度优先遍历见：
https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
 */
class Solution_dfs {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {                //遇到 ‘1’，则陷入，以其为根结点启动深度优先搜索。
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands;
  }
};




/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (46.97%)
 * Likes:    417
 * Dislikes: 0
 * Total Accepted:    68K
 * Total Submissions: 142.7K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */
