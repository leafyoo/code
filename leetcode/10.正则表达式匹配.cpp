// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.size(), pn = p.size();

        vector<vector<bool> > dp(sn+1, vector<bool>(pn+1, false));
        dp[0][0] = true;            //两个空字符串，当然匹配
        dp[0][1] = false;           //p中只有一个字符，不然false

        //s不空、p为空的情况很确定；而s为空p不空的情况却有些特殊(a*b*c*可以匹配空的s)，这里要处理下。
        for( int i = 2; i <= pn; ++i)
        {
            if(p[i-1] == '*' && dp[0][i-2])                     //错误：这里 "*"  应该为 '*'
                dp[0][i] = true;
        }

        for( int i = 1; i <= sn; ++i)
        {
            for( int j = 1; j <= pn; ++j)
            {
                if(p[j-1] == s[i-1] || p[j-1] == '.' )             /* 需要注意dp、string的下标偏差 ，i-1， j-1都是当前正在比较的字符。*/
                    dp[i][j] = dp[i-1][j-1];

                else if(p[j-1] == '*') 
                {
                    if(p[j-2] != s[i-1] && p[j-2] != '.')       /* s当前字符不等于 p当前的前一个字符。则就看p的前面的了 */
                        dp[i][j] = dp[i][j-2];
                    else
                    {   //s当前字符等于 p当前的前一个字符。
                        dp[i][j] = dp[i-1][j]       /* 匹配多个 */
                                    || dp[i][j-1]   /* 匹配一个 */
                                    || dp[i][j-2];  /* 匹配0个 */
                    }
                }
            }
        }
        return dp[sn][pn];
    }
};
// @lc code=end
/*
fish:

题解：https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/


*/


/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (26.03%)
 * Likes:    975
 * Dislikes: 0
 * Total Accepted:    55.6K
 * Total Submissions: 211.5K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */