
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if ( m <= 0 )
        {
            copy(nums2.begin(), nums2.begin() + n, nums1.begin());
            return;
        }
        if(n <= 0)return;

        int i1 = m-1, i2 = n-1, iCur = m+n-1;
        while( i1 >=0 && i2 >= 0 && iCur >= 0)
        {
            if( nums1[i1] < nums2[i2]) 
                nums1[iCur--] = nums2[i2--];
            else
                nums1[iCur--] = nums1[i1--];
        }

        while(i2 >= 0)
        {
            nums1[iCur--] = nums2[i2--] ;
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (46.60%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    110.4K
 * Total Submissions: 236.5K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */
