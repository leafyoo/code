// @lc code=start
class Solution {
public:
    vector<vector<char>> m_board;
    vector<vector<char>> used;
    string m_word;
    int row, col ;
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;     //错误：如果这里没有，则下文board[0]错误

        this->m_board = board;
        this->m_word = word;
        this->row = board.size();
        this->col = board[0].size();

        /*  【知识点】，注意二维vector的resize方法 。  void resize ( n,  val ); */
        used.resize(row, vector<char>(col, 0)); 

        for( int i = 0; i < row; ++i)       // 从二维表格的每一个格子出发
        {
            for( int j = 0; j < col; ++j)
                if( dfs(i, j, 0) ) return true;   
        }
        return false;
    }

    bool dfs(int i, int j, int pos)
    {
        if(i >= row || i < 0 
        || j >= col || j < 0 
        || pos >= m_word.size() 
        || m_board[i][j] != m_word[pos]
        || used[i][j])          //错误：这里少了判断：i < 0 ，因为下面有 i-1
            return false;
        else
        {   //当前字符相等
            if(pos + 1 == m_word.size())              //并且 如果是最后一个字母了，返回成功
                return true;
            
            used[i][j] = true;       //【去重】 标记为已读。先备份当前值，然后清空，避免后面递归时又走回来。          

            if(dfs(i-1, j, pos+1) || dfs(i, j+1, pos+1) 
                || dfs(i+1, j, pos+1) || dfs(i, j-1, pos+1))        //往上、右、下、左 其中一条能走通，就算成功
                return true;
            
            used[i][j] = false;      //【回退】 如果都不通，则回溯上一状态, 恢复原状，以便进行下一次搜索
        }    

        return false;
    }

};
// @lc code=end
/* 
复杂度分析：https://leetcode-cn.com/problems/word-search/solution/tu-jie-di-gui-shen-du-you-xian-sou-suo-by-z1m/
时间复杂度：O((m*n)平方)
空间复杂度：O((m*n))


比较聪明的是将当前的元素置为0，省去了一个备忘录

https://leetcode-cn.com/problems/word-search/solution/hui-su-suan-fa-dai-ma-jian-ji-yi-dong-by-geekwade/
 */


/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.51%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 109.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
