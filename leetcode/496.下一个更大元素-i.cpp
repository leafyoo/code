// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> next(nums1.size(), -1);
        stack<int> stk;         //存储到当前i为止，从左到右看到的最大的数
        unordered_map<int, int> mp;
        
        for( int i = nums2.size() - 1; i >= 0; --i)  // 倒着往栈里放
        {
            int tmp = -1;
            while( !stk.empty() && stk.top() <= nums2[i])   //栈里的小？  那就让开
                stk.pop();                                  

            if( !stk.empty() && stk.top() > nums2[i])       //找到了比自己大的？ 那就记下来
                tmp = stk.top();
            
            stk.push( nums2[i] );           // 进队，等待之后的身高判定吧！
            mp[ nums2[i] ] = tmp;           // nums2[i]这个元素身后的第一个高个
        }

        for( int i = 0; i < nums1.size(); ++i)
            next[i] = mp[ nums1[i] ];       

        return next;
    }

};

/* 
【单调栈】【原理讲解】
为什么叫单调栈呢？
比如这道题，输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
我们看nums2，
栈里的元素，每一次循环之后，栈里的元素永远是从顶部到底部逐渐增大的。


for循环i的值             ： 0，  1，  2，    3       

stack里的值(左边是栈顶)   ：[2], [4], [3,4], [1,3,4]


【题解】
https://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/

链接：https://leetcode-cn.com/problems/next-greater-element-i/solution/496-xia-yi-ge-geng-da-yuan-su-i-c-by-eric-345/

这就是单调队列解决问题的模板。for 循环要从后往前扫描元素，因为我们借助的是栈的结构，倒着入栈，其实是正着出栈。while 循环是把两个“高个”元素之间的元素排除，因为他们的存在没有意义，前面挡着个“更高”的元素，所以他们不可能被作为后续进来的元素的 Next Great Number 了。

作者：labuladong
链接：https://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
