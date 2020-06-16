// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) 
            return 0;
        int n = s.size();
        
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        int cnt = 0;
        for( int i = 0; i < n; ++i)             //初值：处理长度=1 的字符串
        {
            dp[i][i] = true;
            ++cnt;
        }

        for( int i = 1; i < n; ++i)             //初值：处理长度=2 的字符串
        {
            if(s[i-1] == s[i])
            {
                dp[i-1][i] = true;
                ++cnt;
            }
        }

        for( int i = 3; i <= n; ++i)             //i表示回文串的长度, 所以，这里i可以为n
        {
            for( int j = 0; j+i-1 < n; ++j)
            {
                if( dp[j+1][j+i-2] && s[j] == s[j+i-1])
                {
                    dp[j][j+i-1] = true;
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

/* 
fish：

【相似】同第 516 题， 第 5 题


 */

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (60.67%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    18.1K
 * Total Submissions: 29.8K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abc"
 * 输出: 3
 * 解释: 三个回文子串: "a", "b", "c".
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aaa"
 * 输出: 6
 * 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 注意:
 * 
 * 
 * 输入的字符串长度不会超过1000。
 * 
 * 
 */
