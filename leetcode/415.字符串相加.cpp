// @lc code=start
#include <string>
using namespace std;

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        if( num1.empty() ) 
            return num2;
        if( num2.empty() ) 
            return num1;

        string res;
        int up = 0;
        for( int i1 = num1.size() - 1, i2 = num2.size() - 1; i1 >= 0 || i2 >= 0; --i1, --i2 )
        {
            int n1 = (i1 >= 0 ) ? num1[i1] - '0' : 0;
            int n2 = (i2 >= 0 ) ? num2[i2] - '0' : 0;

            res = to_string( (n1+n2+up)%10 ) + res;
            up = (n1+n2+up)/10 ;
        }

        if(up) 
            res = to_string(up) + res;            //也可以：  res += up + '0';

        return res;
    }
};
// @lc code=end
/*
fish：
1、两个数字相加，位数不可能超过两个数字的最大位数+1；
2、错误：num1[i1]是char 而不是 string，所以没有.c_str()这个方法：  atoi( num1[i1].c_str() ) 


*/
/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.45%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    24.2K
 * Total Submissions: 48.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */