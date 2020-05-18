// @lc code=start
class Solution  {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() < 1) return {{}};
        used.resize(nums.size());

        sort(nums.begin(), nums.end());         //根据 nums[i-1] == nums[i]  来去重，这里就需要sort一下
        
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

        for( int i = 0; i < nums.size(); ++i)
        {
            /* 如果nums[i-1]或者nums[i]已经被使用，那说明是第一次，所以nums[i-1] == nums[i]可以相等 */
            if(  used[i] || ( i > 0  && !used[i-1]  && !used[i] && nums[i-1] == nums[i] )  ) 
                continue;      

            used[i] = true;
            path.push_back( nums[i]);

            DFS(nums);

            used[i] = false;
            path.pop_back();
        }   
    }

};

class Solution_set {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() < 1) return {{}};
        used.resize(nums.size());
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

        unordered_set<int> st;  ////枚举的时候去重，只用没有排过的，因为选择重复的数字，得到的子树一样
        for( int i = 0; i < nums.size(); ++i)
        {
            if(used[i] || st.count(nums[i])) continue;      

            used[i] = true;
            st.insert( nums[i]);            
            path.push_back( nums[i]);

            DFS(nums);
            
            //因为是为了避免同一个平层上不相同，所以这里不需要回溯，即不需要st.erase
            used[i] = false;
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
