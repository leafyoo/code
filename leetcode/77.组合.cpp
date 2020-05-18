// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int m_n, m_k;

    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        m_k = k;
        DFS(1 );
        return res;
    }

    void DFS(int beg )       //这里DFS的作用，其实就是再path.push_back下一个 i+1
    {
        if(m_k == path.size())      //这里控制了递归深度为 m_k层
        {
            res.push_back(path);
            return ;
        }
        for( int i = beg; i <= m_n; ++i)
        {
            path.push_back(i);
            DFS(i+1);                 //错误：这里i+1写成了 beg+1。 解释：要和上一次push_back进去的不同，当然只能是i+1
            path.pop_back();
        }
    }

};
// @lc code=end
/* 
https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/

 */


/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (72.72%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    39.3K
 * Total Submissions: 53.7K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
