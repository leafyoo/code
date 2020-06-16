// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        if(n1 < 1 || n2 < 1) return (n1 < 1 ? num2 : num1);
        if(num1 == "0" || num2 == "0") return "0";                  //错误：特殊值未处理。 0 乘任何数为0

        string res;
        
        for( int i = 0; i <= n1 - 1; ++i)   //每次循环以num1的一位分别去乘以 num2的每一位
        {
            //求num1[i] * num2的乘积
            int up = 0, d = num1[i] - '0';
            string strLow;
            for( int j = n2-1; j >= 0; --j)
            {
                int tmp = up + d * (num2[j] - '0');
                strLow = to_string( tmp % 10 ) + strLow;
                up = tmp / 10;
            }
            
            if(up > 0)
                strLow = to_string( up) + strLow;


            //将上次的结果和当前的乘积相加
            up = 0;
            string strHig = (res.empty() ? "" : (res + '0')) ;
            int ih = strHig.size() - 1, il = strLow.size() - 1;
            res.clear();                                                //错误：这里要清空res;
            while( ih >= 0 || il >= 0 )
            {
                int x = ((ih >= 0) ? (strHig[ih--] - '0') : 0);         //错误：类型不匹配。字符要转为数字， 这里漏掉了 -'0'
                int y = ((il >= 0) ? (strLow[il--] - '0') : 0);
                res = to_string( (x + y + up) % 10 ) + res;
                up = (x + y + up) / 10;
            }
            if(up > 0)
                res = to_string( up) + res;
        }

        return res;
    }
};
// @lc code=end
/* fish
例如：“123” * “456”
1 * 456 = 456
2 * 456 = 912
3 * 456 = 1368

45600 +
 9120 +
 1368 +
56088 =

1、 “1” * “456” 得到 strLow；
2、 用

 */
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (41.97%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    51.9K
 * Total Submissions: 123.8K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

