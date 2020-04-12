// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.size(), nb = b.size() ;
        if( !na || !nb ) 
            return (na ? a : b);
        
        string res;
        int i = na - 1, j = nb - 1, up = 0;
        for( ; i >= 0 || j >= 0; )              //从后往前
        {
            int x = ( i >= 0 ? (a[i--] - '0') : 0);
            int y = ( j >= 0 ? (b[j--] - '0') : 0);

            res = to_string( (x+y+up) % 2 ) + res;
            up = (x+y+up) / 2; 
        }

        if(up)
            res = to_string( up ) + res;
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.29%)
 * Likes:    329
 * Dislikes: 0
 * Total Accepted:    71.6K
 * Total Submissions: 137K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

