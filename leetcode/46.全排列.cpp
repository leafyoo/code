// @lc code=start
class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> path;                   //递归路径
    vector<bool> visiting;              //在递归路径上，已入栈的那些位置

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return {{}};

        visiting.resize( nums.size());          //知识点：重设数组大小

        DFS(nums );

        return res;
    }

    void DFS(vector<int>& nums )
    {
        if(path.size() == nums.size())
        {
            res.push_back( path);
            return;
        }

        unordered_set<int> uniq;
        for( int i = 0; i < nums.size(); ++i)
        {
            if(visiting[i]) continue;                   //剪枝

            visiting[i] = true;
            path.push_back( nums[i] );
            
            DFS(nums );

            visiting[i] = false;        
            path.pop_back( );       // backtrack
        }
    }

};
// @lc code=end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.00%)
 * Likes:    565
 * Dislikes: 0
 * Total Accepted:    88.6K
 * Total Submissions: 119.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */