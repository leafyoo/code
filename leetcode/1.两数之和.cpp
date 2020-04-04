// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for( int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];
            if ( mp.find( need ) != mp.end() )
            {
                return {i, mp[need]};
            }
            mp[ nums[i] ] = i;              //fish错误：这里  nums[i]  写成need了
        }

        return {};
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.59%)
 * Likes:    7720
 * Dislikes: 0
 * Total Accepted:    842K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
