// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int m_k;

    vector<vector<int>> combinationSum3(int k, int n) {
        m_k = k;

        DFS( n, 1);                           //错误：这里1写成了0
        return res;
    }

    void DFS( int sum, int b)
    {
        if(path.size() >= m_k || sum <= 0)
        {
            if(path.size() == m_k && sum == 0)
            {
                res.push_back(path);
            }
            return ;
        }

        for( int i = b; i <= 9 && sum >= i; ++i)
        {
            path.push_back(i);
            DFS( sum - i , i+1);
            path.pop_back();
        }
    }

};
// @lc code=end

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (70.28%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 22.7K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
