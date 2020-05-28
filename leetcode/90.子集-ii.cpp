// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> m_nums;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        m_nums = nums;
        
        sort(m_nums.begin(), m_nums.end());

        DFS(0);
        return res;    
    }

    void DFS(int beg)
    {
        res.push_back(path);

        for( int i = beg; i < m_nums.size(); ++i)
        {
            if(i > beg && m_nums[i] == m_nums[i-1])     //平层去重，剪枝：避免出现相同的子集。相同的子树，不进一步递归
                continue;

            path.push_back( m_nums[i] );        //【添加】
            DFS(i + 1);
            path.pop_back();                        //【撤销】
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.00%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    25.5K
 * Total Submissions: 42.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
