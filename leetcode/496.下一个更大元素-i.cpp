// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> next(nums1.size(), -1);
        stack<int> stk;         //存储到当前i为止，从左到右看到的最大的数
        unordered_map<int, int> mp;
        
        for( int i = nums2.size() - 1; i >= 0; --i)
        {
            int tmp = -1;
            while( !stk.empty() && stk.top() <= nums2[i])
                stk.pop();
            if( !stk.empty() && stk.top() > nums2[i])
                tmp = stk.top();
            
            stk.push( nums2[i] );
            mp[ nums2[i] ] = tmp;
        }

        for( int i = 0; i < nums1.size(); ++i)
            next[i] = mp[ nums1[i] ];

        return next;
    }

};

/* 
链接：https://leetcode-cn.com/problems/next-greater-element-i/solution/496-xia-yi-ge-geng-da-yuan-su-i-c-by-eric-345/
 */

// @lc code=end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 *
 * https://leetcode-cn.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (63.42%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 42.8K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2
 * 中的下一个比其大的值。
 * 
 * nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出: [-1,3,-1]
 * 解释:
 * ⁠   对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
 * ⁠   对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
 * ⁠   对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出: [3,-1]
 * 解释:
 * 对于num1中的数字2，第二个数组中的下一个较大数字是3。
 * ⁠   对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
 * 
 * 
 * 注意:
 * 
 * 
 * nums1和nums2中所有元素是唯一的。
 * nums1和nums2 的数组大小都不超过1000。
 * 
 * 
 */
