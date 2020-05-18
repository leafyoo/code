// @lc code=start

//贪心算法
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maxPos = 0;
        for (int curPos = 0; curPos < nums.size(); curPos++)      //探索一下可跳范围里，最大能力
        {
            if (curPos > maxPos)            //能跳到的最远的点已经不能覆盖当前点了，结束
                return false;

            maxPos = max(maxPos, curPos + nums[curPos]);        //把能跳到最远的点 不断更新。
        }
        
        return true;
    }

};
/* 
因为是“可以跳跃的最大长度” ，也就是可以跳 0 - x步之间任何一个数，
所以可以用贪心算法，不用担心跳得太多而错过


时间复杂度：O(n) ，只需要访问 nums 数组一遍，共 n  个位置，n 是 nums 数组的长度。
空间复杂度：O(1) ，不需要额外的空间开销。

https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
 */


class Solution_dp {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 1) return true;

        vector<bool> dp(n, false);
        dp[n-1] = true;

        for( int i = n-2; i >= 0; --i)
        {
            int maxJump = ((i+nums[i]) >= n ? n-i-1 : nums[i] );          //这里的条件可以等到下面的for写完之后再从这里补齐
            for( int j = 1; j <= maxJump; ++j)
            {
                if( dp[i+j] )
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0] ;
    }

};
/* 
时间复杂度：O(n^2)，数组中的每个元素，假设为 i，需要搜索右边相邻的 nums[i] 个元素查找是否有 GOOD 的坐标。 nums[i] 最多为 n，n 是 nums 数组的大小。
空间复杂度：O(n)，记忆表的存储开销。

作者：LeetCode
链接：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode/
 */
/* 
Time Limit Exceeded
74/75 cases passed (N/A)

 */


class Solution_recursion {
public:
    vector<int> m_nums;
    bool canJump(vector<int>& nums) {
        m_nums = nums;
        return jump( 0);
    }

    bool jump( int pos)
    {
        if(pos == m_nums.size() - 1) return true;
        if(pos >= m_nums.size()) return false;

        for( int i = 1; i <= m_nums[pos]; ++i)
        {
            if( jump(  pos+i) )
                return true;
        }

        return false;
    }

};
// @lc code=end
/* 
Time Limit Exceeded
74/75 cases passed (N/A)

 */


/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.02%)
 * Likes:    499
 * Dislikes: 0
 * Total Accepted:    68.8K
 * Total Submissions: 179.4K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个位置。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,1,0,4]
 * 输出: false
 * 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * 
 * 
 */
