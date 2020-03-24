// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    int range;
    
    vector<vector<string>> solveNQueens(int n) {
        if(n < 1) return res;
        this->range = n;
        vector<vector<char>> oneRes(n, vector<char>(n, '.'));
        dfs( oneRes, 0);
        return res;
    }

    void dfs(vector<vector<char>> &oneRes, int ri)
    {
        if(ri == range )
        {
            vector<string> vecOneRow;
            for( int i = 0; i < oneRes.size(); ++i)
                vecOneRow.push_back( accumulate(oneRes[i].begin(), oneRes[i].end(), (string)"" ) );         //错误：这里少了 (string) 会报错
            res.push_back(vecOneRow);
            return;
        }

        for( int ci = 0; ci < range; ++ci)
        {
            if( isOk(oneRes, ri, ci) )
            {
                oneRes[ri][ci] = 'Q';
                dfs(oneRes, ri + 1);
                oneRes[ri][ci] = '.';       //回溯
            }
        }
    }

    bool isOk(vector<vector<char>> &oneRes, int ri, int ci )
    {
        for( int i = 0; i < ri; ++i)                                        //1、纵向。 递归里按横向遍历，所以横向合法
            if(oneRes[i][ci] == 'Q') return false;

        for( int i = ri, j = ci; i >= 0 && j >= 0; --i, --j)                //2、主对角线
            if(oneRes[i][j] == 'Q') return false;

        for( int i = ri, j = ci; i >= 0 && j < oneRes.size(); --i, ++j)     //3、副对角线
            if(oneRes[i][j] == 'Q') return false;

        return true;
    }
};
// @lc code=end
/*
ri: row index
ci：col index


https://leetcode-cn.com/problems/n-queens/solution/jing-dian-hui-su-qiu-jie-jian-dai-ma-zhu-shi-by-hw/


 */


/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.09%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 44.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */
