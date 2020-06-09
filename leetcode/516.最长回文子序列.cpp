
// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty()) return 0;

        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));          //二维矩阵的左下侧全是0 （因为其实位置i比终止位置j还小，显然字符串长度0）

        for( int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for( int i = n-2; i >= 0; --i)                          //因为下文用到i+1，所以i递减变化可以保证大的值先被求好了
        {
            for( int j = i+1; j < n; ++j)                       //因为下文用到j-1，所以j递增变化可以保证小的值先被求好了
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);     //转移方程可以先写出来的，因为 我们考察的是从 i 到 j。 然后在确定上面的范围；i、j的增减顺序
            }
        }

        return dp[0][n-1];
    }
};
// @lc code=end
/*
【相似】同第 5 题，只是这里只要求最大的长度，这里dp代表的“最大长度”

fish:
画矩阵图！！！
这里的思路很赞！！！
https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zi-xu-lie-wen-ti-tong-yong-si-lu-zui-chang-hui-wen/

dp[i][j] :表示从i到j范围内的最大子序列长度


*/


/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (50.20%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 25.3K
 * Testcase Example:  '"bbbab"'
 *
 * 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
 * 
 * 示例 1:
 * 输入:
 * 
 * 
 * "bbbab"
 * 
 * 
 * 输出:
 * 
 * 
 * 4
 * 
 * 
 * 一个可能的最长回文子序列为 "bbbb"。
 * 
 * 示例 2:
 * 输入:
 * 
 * 
 * "cbbd"
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 一个可能的最长回文子序列为 "bb"。
 * 
 */
