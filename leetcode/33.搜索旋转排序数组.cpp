
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0, e = nums.size() - 1;

        while( b <= e )
        {
            int m = (b+e)/2;
            if(target == nums[m])
                return m;

            if ( nums[b] <= nums[m] )                                //错误：这里要有 = ，因为可能是  3333012这种，  口诀：【能等则等】
            {//左半边有序
                if( nums[b] <= target && target < nums[m])      //左左
                    e = m - 1;
                else
                    b = m + 1;
            }
            else
            {//右半边有序
                if( nums[m] < target && target <= nums[e])      //右右
                    b = m + 1;
                else
                    e = m - 1;
            }
        }

        return -1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.41%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    75.1K
 * Total Submissions: 206.3K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */
