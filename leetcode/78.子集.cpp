// @lc code=start

//回溯
class Solution_backtrack {
public:
    vector<vector<int>> res;
    vector<int> oneRes;

    vector<vector<int>> subsets(vector<int>& nums) {
        subs(nums, 0);
        return res;
    }

    void subs(vector<int>& nums, int pos) {
        res.push_back(oneRes);
        
        for( int i = pos; i < nums.size(); ++i)
        {
            oneRes.push_back( nums[i]);
            subs(nums, i+1);                    //错误：这里是i+1，而不是 pos+1
            oneRes.pop_back( );     // backtrack
        }
    }
};
/* 
https://leetcode.com/problems/subsets/discuss/27278

 */


class Solution {
public:
    vector<vector<int>> res;
    vector<int> oneRes;

    vector<vector<int>> subsets(vector<int>& nums) {
        subs(nums, nums.size());
        return res;
    }

    //前preCnt个数的子集（前缀） = 前(preCnt-1)个数的子集 + （前(preCnt-1)个数的子集 追加 第preCnt个数）
    vector<vector<int>>  subs(vector<int>& nums, int preCnt) {
        if(preCnt == 0)
        {
            res.push_back( {} );
        }
        else
        {
            vector<vector<int>> preRes = subs(nums, preCnt-1);

            res = preRes;               //先把上一层的结果完全拷贝一份，然后下面继续追加

            for( int i = 0; i < preRes.size(); ++i)
            {
                preRes[i].push_back( nums[preCnt-1] );          //追加上第preCnt个数
                res.push_back( preRes[i] );
            }
        }

        return res;
    }
};

/* 
https://leetcode-cn.com/problems/subsets/solution/dong-tai-gui-hua-fa-qiu-ji-he-de-zi-ji-by-ya-ya-51/

 */

// @lc code=end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.39%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 90.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
