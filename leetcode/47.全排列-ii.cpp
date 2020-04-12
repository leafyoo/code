// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visiting;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() < 1) return {{}};
        visiting.resize(nums.size());
        DFS(nums);
        return res;
    }

    void DFS(vector<int>& nums)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return ;
        }

        unordered_set<int> st;                      ////枚举的时候去重，只用没有排过的，因为选择重复的数字，得到的子树一样
        for( int i = 0; i < nums.size(); ++i)
        {
            if(visiting[i] || st.count(nums[i])) continue;      

            visiting[i] = true;
            st.insert( nums[i]);
            path.push_back( nums[i]);

            DFS(nums);

            visiting[i] = false;
            path.pop_back();
        }   
    }

};
// @lc code=end
/* fish
递归树的图片：
https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/

 */


/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (56.92%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 77.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
