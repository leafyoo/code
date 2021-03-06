// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n < 10 || n < INT_MIN || n > INT_MAX) 
            return -1;
        
        //转换int为字符串数组
        vector<int> v;
        for( int i = n; i > 0; i /= 10)
            v.push_back( i % 10 );
        reverse(v.begin(), v.end());

        //从后向前，找降序转折点
        int sm = v.size() - 2;
        while( sm >= 0 && v[sm] >= v[sm+1])
            --sm; 
        if(sm < 0) 
            return -1;

        //从后向前，找刚好大于small一点点的值，然后交换
        int big = v.size() - 1;
        while(big >= 0 && v[big] <= v[sm] )
            --big;
        swap(v[sm], v[big]);
        
        //反转后半部分的降序区间
        reverse(v.begin() + sm+1, v.end());

        //整理成数字
        long long res = 0;
        for( int i = 0; i < v.size(); ++i)
            res = res * 10 + v[i];

        if(res < INT_MIN || res > INT_MAX) 
            return -1;   //错误：没有判断极值、溢出
        
        return (int)res;
    }
};
// @lc code=end
/* fish
例：2 7 6 5
原理及动画：
https://leetcode-cn.com/problems/next-greater-element-iii/solution/xia-yi-ge-geng-da-yuan-su-iii-by-leetcode/

 */

/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 *
 * https://leetcode-cn.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (30.08%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 12.3K
 * Testcase Example:  '12'
 *
 * 给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回-1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 12
 * 输出: 21
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 21
 * 输出: -1
 * 
 * 
 */

