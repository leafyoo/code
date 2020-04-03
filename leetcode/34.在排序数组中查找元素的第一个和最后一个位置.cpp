// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;

        res[0] = left_bound(nums, target);
        res[1] = right_bound(nums, target);

        return res;
    }

    int left_bound(vector<int>& nums, int target)
    {
        int b = 0, e = nums.size() -1;
        while( b <= e )
        {
            int m = (b+e)/2;
            if(nums[m] == target)
                e = m-1;            //终点左移，使得搜索区间进一步往左侧逼近。
            else if(nums[m] < target)
                b = m+1;
            else
                e = m-1;
        }
        
        if(b >= nums.size() || nums[b] != target)
            return -1;

        return b;
    }

    int right_bound(vector<int>& nums, int target)
    {
        int b = 0, e = nums.size() -1;
        while( b <= e )
        {
            int m = (b+e)/2;
            if(nums[m] == target)
                b = m+1;                //起点右移，使得搜索区间进一步往右侧逼近。
            else if(nums[m] < target)
                b = m+1;
            else
                e = m-1;
        }
        
        if(e < 0 || nums[e] != target)
            return -1;

        return e;       //这里要返回e，只能尽量确保e不要错过target，所以，在上面 (nums[m] == target)时，只能收缩 b
    }

};
// @lc code=end
/* 
fish:
1、注意：二分法里， beg 永远只能+1， end永远只能-1，因为beg从0开始，beg-1面临溢出的风险。

2、题解
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/

1、为什么这个算法能够找到右侧边界？
答：类似地，关键点还是这里：
if (nums[mid] == target) {
    left = mid + 1;
当 nums[mid] == target 时，不要立即返回，而是增大「搜索区间」的下界 left，使得区间不断向右收缩，达到锁定右侧边界的目的。


 */


/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.99%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    64.1K
 * Total Submissions: 164.2K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */
