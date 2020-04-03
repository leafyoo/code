// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int b = 0, e = n - 1;
        while( b < e )
        {
            int m = (b+e)/2;
            if(nums[m] > nums[m+1])
                e = m;          //m 大于 m+1，那m处才可能是峰值
            else
                b = m+1;        //m+1 大于 m，那m+1处才可能是峰值
        }
     
        return e;       //【重要知识】return b;也可以。 因为上面结束条件是： b==e 
                        //（b和e在循环里，每次只能有其中一个加一或者减一，所以肯定有相等的那一刻）
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (45.31%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    33.4K
 * Total Submissions: 73.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
 * 
 */
