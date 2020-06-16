// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if(grid.empty() || grid[0].empty()) 
            return 0;

        queue< pair<int, int> > q;
        int nr = grid.size(), nc = grid[0].size();
        int fresh = 0;
        for( int i = 0; i < nr; ++i)
        {
            for( int j = 0; j < nc; ++j)
            {
                if(grid[i][j] == 1)                         //注意：这里要统计新鲜橘子的数量
                    ++fresh;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int level = 0;
        vector<vector<int> > dir = { {0, 1},{0, -1},{1, 0},{-1, 0} };
        while( !q.empty() )
        {
            int qn = q.size();
            bool meetRot = false;
            for( int i = 0; i < qn; ++i)
            {
                int qr = q.front().first;                 //错误：写成了 q.top()， 应该是front!
                int qc = q.front().second;
                q.pop();

                for( int j = 0; j < dir.size(); ++j)
                {
                    int r = qr + dir[j][0];
                    int c = qc + dir[j][1];
                    if(r >= 0 && r < nr && c >= 0 && c < nc 
                        && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        q.push( {r, c} );
                        --fresh;
                        meetRot = true;
                    }
                }
            }

            if(meetRot )                    //错误：逻辑错误：少了if(meetRot )  判断，下一层可能没有新鲜橘子的
                ++level;
        }

        if(fresh == 0)
            return level;
        else
            return -1;
    }
};
// @lc code=end
/* 
fish: BFS
BFS只是一种思想，并不是tree的专属

 */



/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode-cn.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (50.76%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 46.8K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的网格中，每个单元格可以有以下三个值之一：
 * 
 * 
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 * 
 * 
 * 每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
 * 
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] 仅为 0、1 或 2
 * 
 * 
 */

