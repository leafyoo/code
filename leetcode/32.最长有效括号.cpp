// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n < 2) return 0;

        vector<int> dp(n, 0);                   //错误：这里用了n+1，导致下文逻辑混乱，更难以厘清了

        for( int i = 1; i < n; ++i)            //解释：因为第一个位置无论是哪个字符，都无法判断出dp，所以干脆从1开始。
        {
            if ( s[i] == '(') continue;
            else if( s[i] == ')' )
            {
                if( s[i-1] == '(' )
                    dp[i] = 2 + ( ( i - 2 >= 0) ? dp[i - 2] : 0 );          //错误：这里?号表达式整体要加括号！
                else
                {//s[i-1] == ')' ，即：‘‘.......))”

                    int begIndex = i - dp[i-1] - 1;                         //不知道是否 -1 ？ 可以假设dp[i-1] 为0往里套
                    if(begIndex >= 0 && s[ begIndex ] == '(')               //解释：形如 ‘‘.......))" 
                    {
                        dp[i] = dp[i-1] + 2;
                        if( begIndex - 1 >= 0 )        //解释：对于这种：()((  )) ，处理完下标为5的括号之后，还要加上第一二个括号
                            dp[i] += dp[begIndex - 1 ];
                    }
                }
            }
            // std::cout<< i << ":" << dp[i] << std::endl;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (29.64%)
 * Likes:    530
 * Dislikes: 0
 * Total Accepted:    40.8K
 * Total Submissions: 137.4K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
