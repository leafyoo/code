// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), res = 0, maxIndex = 0, end=0;
        for( int i = 0; i < n-1; ++i)               //错误：这里是n-1
        {
            maxIndex = max(maxIndex, i+nums[i]);    //找能跳的最远的点
            if(i == end)                            //遇到边界，就更新边界，并且步数加一
            {
                end = maxIndex;
                ++res;
            }
        }

        return res;
    }
};
// @lc code=end
/* 
https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
 */


/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (33.10%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    33.9K
 * Total Submissions: 101.5K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 示例:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 说明:
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 */
