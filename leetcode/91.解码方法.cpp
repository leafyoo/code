// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n < 1) return 0;

        vector<int> dp(n+1, 0);
        if(s[0] == '0') return 0;
        if(n == 1) return 1;
        
        dp[0] = 1;      //注意：要初始化为1
        dp[1] = 1;

        for( int i = 2; i <= n; ++i)
        {
            if(s[i-1] == '0' )
            {
                if(s[i-2] >= '3' || s[i-2] == '0') 
                    return 0;
                dp[i] = dp[i-2];            //错误：写成了dp[i-1]， 当前位置是0， 会连累前一位，导致结果是dp[i-2]
            }
            else if(s[i-1] >= '1' && s[i-1] <= '6') 
            {
                if(s[i-2] == '1'|| s[i-2] == '2' )
                    dp[i] = dp[i-1] + dp[i-2];  //分开，连起来
                else
                    dp[i] = dp[i-1];    //分开
            }
            else if( s[i-1] > '6') 
            {
                if(s[i-2] == '1' )
                    dp[i] = dp[i-1] + dp[i-2];//分开，连起来
                else
                    dp[i] = dp[i-1];    //分开            
            }
        }

        return dp[n];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.10%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    34.5K
 * Total Submissions: 148.4K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */
