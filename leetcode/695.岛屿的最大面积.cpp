// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {            //注意：这里是int，不是char
        if(grid.empty() || grid[0].empty()) return 0;
        int res = 0;

        int nr = grid.size(), nc = grid[0].size();
        vector<vector<int>> dir = {{0, 1},{0, -1},{1, 0},{-1, 0}};

        for( int i = 0; i < nr; ++i)
        {
            for( int j = 0; j < nc; ++j)
            {
                //陷入，一次性腐蚀完所有1
                if(grid[i][j] == 1)                     //错误：这里是数字1   ！！！而不是 字符 '1'， if(grid[i][j] == '1')
                {
                    int tmpRes = 0;
                    queue< pair<int, int> > q;
                    q.push( {i, j} );
                    grid[i][j] = 0;                     //每一次入队，都有消除当前节点
                    
                    while( !q.empty() )
                    {
                        int oldr = (q.front()).first, oldc = (q.front()).second ;                       
                        q.pop();
                        ++tmpRes;                        //在这里累加面积就好了： 队列入队的数量就是岛屿面积

                        for( int i = 0; i < 4; ++i)     //上下左右
                        {
                            int r = oldr + dir[i][0], c = oldc + dir[i][1];
                            if(r >= 0 && r < nr && c >= 0 && c < nc && grid[r][c] == 1)
                            {
                                q.push( {r, c} );                    
                                grid[r][c] = 0;
                            }
                        }
                    }

                    res = max(res, tmpRes);
                }
            }
        }

        return res;
    }
};

// @lc code=end
/* 
fish：这里的bfs，其实是围绕一个点，向四面八方展开的广度遍历，而不是单纯向下或向哪里

 */


/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (59.58%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    37.5K
 * Total Submissions: 59.3K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 * 
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
 * 0（代表水）包围着。
 * 
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
 * 
 * 
 * 
 * 示例 1:
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * 
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
 * 
 * 示例 2:
 * 
 * [[0,0,0,0,0,0,0,0]]
 * 
 * 对于上面这个给定的矩阵, 返回 0。
 * 
 * 
 * 
 * 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 * 
 */
