// @lc code=beg

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        this->candidates = candidates;

        std::sort(this->candidates.begin(), this->candidates.end());    //为了结果集里的去重
        
        DFS(0, target);

        return res;
    }

    void DFS(int beg, int target) 
    {
        if (target == 0) 
        {
            res.push_back(path);
            return;
        }

        for (int i = beg; i < candidates.size(); i++) 
        {       
            if(candidates[i] > target )//【剪枝】 在数组sort后有序的前提下，剪枝  target - candidates[i] >= 0 
                break;
            
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);     //在搜索起点 beg 之前的数因为以前的分支搜索过了，所以一定会产生重复，下一层递归搜索要从i开始。
            path.pop_back();
        }
    }

//【fish注意：】这里添加了数据成员，使得程序可读性更高，递归效率更高
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;

};





//【解法2】无数据成员版本（每次都要在递归中传递参数，效率低一些）
class Solution_noDataMember {

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        DFS(0, target, candidates, path, res);
        return res;
    }

    void DFS(int beg, int target, vector<int> &candidates, vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = beg;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i], candidates, path, res);
            path.pop_back();
        }
    }

};
// @lc code=end
/*

https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
*/


/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (68.40%)
 * Likes:    538
 * Dislikes: 0
 * Total Accepted:    65.1K
 * Total Submissions: 95.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */
