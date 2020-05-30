// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> candidates;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())return {};

        this->candidates = candidates;   //！！！！重要：这里声明局部变量的好处是：下面sort之后，只是改变本地的vector，而外部传入的vector不会被改变。
        
        sort(this->candidates.begin(), this->candidates.end());     //错误：这里少了this->， 导致排序的只是candidates。
        
        DFS(0, target);

        return res;
    }

    void DFS(int beg, int target)
    {
        if(target == 0)
        {
            res.push_back( path);
            return ;
        }    
        
        for( int i = beg; i < candidates.size() ; ++i)
        {
            if(candidates[i] > target )//在数组sort后有序的前提下，剪枝  target - candidates[i] >= 0 
                break;

            //这里是continue，表示在平层里，只是跳过当前节点；而上面是break，表示平层里其他后面的节点均跳过
            /*剪枝：连续相同数字会造成重复的组合数组，这里为了确保，同一个平层上（同一个for循环）不会长出两个一样的树支*/
            if( i > beg && candidates[i] == candidates[i-1] )   
                continue;                                    

            path.push_back( candidates[i]);
            DFS( i+1, target - candidates[i] );             // 元素不可重复利用，使用下一个即i+1
            path.pop_back();
        }
    }
};
// @lc code=end
/* 
https://leetcode-cn.com/problems/combination-sum-ii/solution/hen-qing-shuang-de-cban-hui-su-fa-by-xiaoneng/

https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/

 */


/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.12%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    45K
 * Total Submissions: 74.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */
