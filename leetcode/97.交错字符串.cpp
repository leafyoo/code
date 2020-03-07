// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if ( n3 != n2 + n1 )
            return false;

        vector<vector<bool> > dp(n1+1, vector<bool>(n2+1, 0));

        //为什么这里要处理这 3个 特殊状态？ 因为：下文主循环会有j-1
        dp[0][0] = true;
        for( int i = 1; i <= n1 && i <= n3; ++i)
            dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i+0-1]);    //这里用这个表达式，为了和下面主循环里的一致，j在这里为0
            
        for( int j = 1; j <= n2 && j <= n3; ++j)
            dp[0][j] = (dp[0][j-1] && s2[j-1] == s3[0+j-1] );   //错误：这里漏了dp[0][j-1]

        for( int i = 1; i <= n1; ++i)
        {
            for( int j = 1; j <= n2; ++j)
            {
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1] )
                        || (dp[i-1][j] && s1[i-1] == s3[i+j-1]); 
            }
        }
        
        return dp[n1][n2];
    }
};
// @lc code=end

/* fish
题解：
https://leetcode-cn.com/problems/interleaving-string/solution/jiao-cuo-zi-fu-chuan-by-leetcode/#comment


 */

/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (38.66%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 26.1K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出: false
 * 
 */
