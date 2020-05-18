// @lc code=start
class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> path;                   //递归路径
    vector<bool> used;              //在递归路径上，已入栈的那些位置

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return {{}};

        used.resize( nums.size());          //知识点：重设数组大小

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

        for( int i = 0; i < nums.size(); ++i)
        {
            if(used[i]) continue;                   //【剪枝】 去重

            //这样去重也可以，只是性能差一些
            // if( find(path.begin(), path.end(), nums[i]) != path.end()) continue;

            used[i] = true;
            path.push_back( nums[i] );
            
            DFS(nums );

            used[i] = false;        
            path.pop_back( );       // backtrack
        }
    }

};
// @lc code=end
/* fish
递归树的图片：
https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/


这里不能通过：

for( int i = 0; 
DFS(nums , i+1) 的方式来搞，这样的话，路会走死，只有一个结果：
[1,2,3]

因为一层遍历时，第一层 i=1， 第二层 i可能是 i=4， 那序列就是： 1 4， 不连续，所以不能根据beg来去重

 */


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