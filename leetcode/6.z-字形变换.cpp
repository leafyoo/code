// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string res;

        int term = 2*numRows - 2;                   //周期
        for( int i = 0; i < numRows; ++i)
        {
            for( int j = i; j < s.size(); j += term )   //一个周期内，可能有2个元素
            {
                res += s[j] ;
                int secondJ = j + 2*(numRows - i - 1) ;     //看下面的验证用例，注意，要从0开始！才能推导正确
                if( i != 0 && i != (numRows-1) && secondJ < s.size())
                {
                    res += s[ secondJ ] ;
                }
            }
        }

        return res;
    }
};
// @lc code=end

/* 
fish：
验证用例：

0    6
1  5 7
2 4  8  10
3    9


题解：
图看这里：
https://leetcode-cn.com/problems/zigzag-conversion/solution/mo-ni-guo-cheng-he-zhao-gui-lu-by-powcai/

代码看这里：
https://leetcode.com/problems/zigzag-conversion/discuss/3417
 */


/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.69%)
 * Likes:    606
 * Dislikes: 0
 * Total Accepted:    108.5K
 * Total Submissions: 229.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */
