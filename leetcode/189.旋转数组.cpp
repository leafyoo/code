// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2) 
            return;

        k = k % nums.size();        //重要：注意，求余！！

        reverse(nums.begin(), nums.end());              //先整体反转，再局部反转
        
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

/*
reverse函数：
void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }

超时： 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2) return;
        k = k % nums.size();
        for(;k>0; --k)
        {
            int t = nums[ nums.size()-1 ];
            for( int i = nums.size()-1; i >0; --i)
            {
                nums[i] = nums[i-1];
            }    
            nums[0] = t;
        }
    }
};

 */

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (40.43%)
 * Likes:    494
 * Dislikes: 0
 * Total Accepted:    99.2K
 * Total Submissions: 244.9K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的 原地 算法。
 * 
 * 
 */
