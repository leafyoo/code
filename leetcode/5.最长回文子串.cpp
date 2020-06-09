// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        
        int len = s.size(), max = 1, beg = 0;
        vector<vector<bool> > dp(len, vector<bool>(len) );

        //1 ： 先将长度1的dp赋初值
        for( int i = 0; i < len; ++i)
            dp[i][i] = true;

        //2 ： 先将长度2的dp赋初值
        for( int i = 0; i+1 < len; ++i)
        {
            if ( s[i] == s[i+1] )
            {
                beg = i;
                max = 2;                            //错误：这里漏了
                dp[i][i+1] = true;
            }
                
        }

        //3 ： 从长度3开始的 dp 赋值推导， i：表示长度
        for( int i = 3; i <=len; ++i)
        {
            for( int j = 0; j+i-1 < len; ++j)      //这里j的条件可以等后面再补上，根据下文的数组的下标
            {
                if(s[j] == s[j+i-1] && dp[j+1][j+i-2])
                {
                    dp[j][j+i-1] = true;
                    beg = j;
                    max = i;
                }
            }
        }

        return s.substr(beg, max);
    }
};
// @lc code=end

/*
【相似】同第 647 、 516 题，只是这里不dp代表的 “是/否”

fish:
【复杂度】 时间复杂度：O (n2), 空间复杂度 O (n2)
1、题解：
https://www.jianshu.com/p/8ebb7793fa68

2、优化：
【中心展开法】
时间复杂度：O (n2), 空间复杂度 O(1）

【暴力破解】
时间复杂度：两层 for 循环 O(n²） ，for 循环里边判断是否为回文 O(n） ，所以时间复杂度为 O(n³） 。
空间复杂度：O(1） ，常数个变量。


*/

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.52%)
 * Likes:    1792
 * Dislikes: 0
 * Total Accepted:    190.8K
 * Total Submissions: 665.3K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */