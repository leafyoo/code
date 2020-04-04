// @lc code=start
/*
fish:

beg: b
end: e
vector :  v
m:  middle

作者：powcai
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/shuang-zhi-zhen-by-powcai/


[nums1[:left1],nums2[:left2]     |    nums1[left1:], nums2[left2:]]

[ [a1],[b1,b2,b3]     |    [a2,..an],[b4,...bn] ]

我们只需要比较 b3 和 a2 的关系的大小，就可以知道这种分法是不是准确的！
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) 
            return findMedianSortedArrays(nums2, nums1);

        int halfCnt = (n1 + n2 + 1)/2;
        int beg = 0;
        int end = n1;

        while(beg < end)
        {
            int i1 = (beg + end)/2;     //取nums1数组的中位数，nums1的左半边的个数
            int i2 = halfCnt - i1;      //在nums2的左半边还需要的数的个数
            if(nums1[i1] < nums2[i2-1])     //nums1的左半部分小了，那肯定要增大nums1的选择，自然要调整beg
                beg = i1 + 1;
            else
                end = i1;
        }

        //一个中点的情况
        int i1 = beg;
        int i2 = halfCnt - beg;
        int mid1 = INT_MIN;

        int mid1 = max(i1 <= 0 ? INT_MIN:nums1[i1-1],  i2 <= 0 ? INT_MIN:nums2[i2-1]);
        if((n1 + n2)%2 == 1)
            return mid1;

        //两个中点的情况
        int mid2 = min(i1 >= n1 ? INT_MAX: nums1[i1],  i2 >= n2 ? INT_MAX : nums2[i2]);
        return (mid1 + mid2) * 0.5;
    }
};

// @lc code=end
/*
fish: 思路 ，压缩问题规模
*/
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.82%)
 * Likes:    2184
 * Dislikes: 0
 * Total Accepted:    144.5K
 * Total Submissions: 392.1K
 * Testcase Example:  '[1,3]\len2[2]'
 *
 * 给定两个大小为 len1 和 len2 的有序数组 v1 和 v2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(len1 + len2))。
 * 
 * 你可以假设 v1 和 v2 不会同时为空。
 * 
 * 示例 1:
 * 
 * v1 = [1, 3]
 * v2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * v1 = [1, 2]
 * v2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

