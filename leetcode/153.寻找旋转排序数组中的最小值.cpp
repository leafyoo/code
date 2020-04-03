// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int b = 0, e = n - 1;
        while( b < e )
        {
            int m = (b+e)/2;
            if(nums[m] > nums[e])
                b = m+1;
            else
                e = m; 
        }

        return nums[b];
    }
};
// @lc code=end

/* 
左右不对称的原因是：
这是循环前升序排列的数，左边的数小，右边的数大，而且我们要找的是最小值，肯定是偏向左找，所以左右不对称了。
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/

 */

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (50.19%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 76K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 * 
 */
