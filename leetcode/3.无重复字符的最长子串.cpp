// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) return n;
        
        int res = 1;
        unordered_set<char> st;
        st.insert(s[0]);
        for( int b = 0, e = 1; b < n && e < n; )
        {
            if(st.find(s[e]) == st.end())
            {
                res = max(res, e-b+1);
                st.insert(s[e]);
                ++e;                    //错误：这里++j要在局部最后面
            }
            else
            {
                //寻找新的起点，即找不重复的点
                while(b < e && s[b] != s[e])        //错误：这里，要多枚举几种重复的情况，然后看怎么处理
                {
                    st.erase(s[b]);     //这里会erase，所以上面要有s[b] != s[e]
                    ++b;
                }
                ++b;
                ++e;
            }
        }
        return res;
    }
};
// @lc code=end
/* 
fish
时间复杂度：O(2n) = O(n) 
unordered_set的插入删除 O（1）复杂度。

优化：
可以用map代替set，map的value记录index，就可以避免 while(b < e && s[b] != s[e]) 来循环比较。

 */


/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.91%)
 * Likes:    3277
 * Dislikes: 0
 * Total Accepted:    381.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
