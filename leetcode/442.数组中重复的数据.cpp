// @lc code=start

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for( int i = 0; i < nums.size(); )                          //错误：这里多了++i
        {
            if(nums[i] == i+1 || nums[i] == nums[ nums[i]-1 ])
                ++i;
            else                                                    //错误：这里要有else
                swap(nums[i], nums[ nums[i]-1 ]);
        }

        for( int i = 0; i < nums.size(); ++i)
        {
            if( nums[i] != i+1 )   
                res.push_back(nums[i]);         //【相似】类似于 448题，只是这里不同
        }
        
        return res;
    }
};
// @lc code=end
/*
fish: 
1、注意审题： 题目中已经说了，元素出现次数不会大于2：说了“其中有些元素出现两次而其他元素出现一次。”，


*/


/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (63.59%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 18.8K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 * 
 * 找到所有出现两次的元素。
 * 
 * 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 * 
 * 示例：
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [2,3]
 * 
 * 
 */
