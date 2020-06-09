// @lc code=start
class Solution {
public:
    vector< pair<int, int> > dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int m_nr, m_nc;

    void solve(vector<vector<char>>& board) 
    {
        if(board.size() < 3 || board[0].size() < 3 ) 
            return;

        this->m_nr = board.size();
        this->m_nc = board[0].size();

        for( int i = 0; i < m_nr; ++i)        //标记两条纵边
        {
            if(board[i][0] == 'O')
                clean(board, i, 0);
            if(board[i][m_nc-1] == 'O')
                clean(board, i, m_nc-1);
        }
        
        for( int j = 0; j < m_nc; ++j)        //标记两条横边
        {
            if(board[0][j] == 'O')
                clean(board, 0, j);
            if(board[m_nr-1][j] == 'O')
                clean(board, m_nr-1, j);
        }

        for( int i = 0; i < m_nr; ++i)        //标记O、还原O
        {
            for( int j = 0; j < m_nc; ++j)
            {
                if( board[i][j] == 'O')
                    board[i][j] = 'X';              //错误：拼写错误为 board[r]][c]了
                else if( board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }

    void clean(vector<vector<char>>& board, int row, int col)
    {
        board[row][col] = '*';
        for( int i = 0; i < dir.size(); ++i)
        {   
            int r = dir[i].first + row;
            int c = dir[i].second + col;
            
            if(r >= 0 && r < m_nr && c >= 0 && c < m_nc)
            {
                if(board[r][c] == 'O')
                    clean(board, r, c);
            }
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (39.70%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 67.8K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

