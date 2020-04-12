// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(), cnt = 0;
        for( int i = 0; i < n; )                                 //错误：这里读了i++
        {
            //1 ： 只能以这些开头
            if( (data[i] & 0b10000000) ==  0b00000000 )           //错误：严重错误：写成了16进制：0x10000000
                cnt = 0;    
            else if( (data[i] & 0b11100000) ==  0b11000000 )      //错误：优先级问题。这里(data[i] & 0b11100000)  少了括号
                cnt = 1;
            else if( (data[i] & 0b11110000) ==  0b11100000 )
                cnt = 2;
            else if( (data[i] & 0b11111000) ==  0b11110000 )
                cnt = 3;
            else                                                 //错误：不可以： if( (data[i] & 0b11000000) !=  0b10000000 )
                return false;
            
            //2 ： 收尾
            ++i;
            while( i < n && ((data[i] & 0b11000000) ==  0b10000000) )
            {
                --cnt;
                ++i;
            }
            if( cnt != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
/* 
fish:
https://leetcode-cn.com/problems/utf-8-validation/solution/qing-xi-de-jie-fa-by-jason-2/

 */


/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 *
 * https://leetcode-cn.com/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (37.17%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 11.7K
 * Testcase Example:  '[197,130,1]'
 *
 * UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
 * 
 * 
 * 对于 1 字节的字符，字节的第一位设为0，后面7位为这个符号的unicode码。
 * 对于 n 字节的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1
 * 位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。
 * 
 * 
 * 这是 UTF-8 编码的工作方式：
 * 
 * 
 * ⁠  Char. number range  |        UTF-8 octet sequence
 * ⁠     (hexadecimal)    |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠  0000 0000-0000 007F | 0xxxxxxx
 * ⁠  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * ⁠  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 * 
 * 
 * 给定一个表示数据的整数数组，返回它是否为有效的 utf-8 编码。
 * 
 * 注意:
 * 输入是整数数组。只有每个整数的最低 8 个有效位用来存储数据。这意味着每个整数只表示 1 字节的数据。
 * 
 * 示例 1:
 * 
 * 
 * data = [197, 130, 1], 表示 8 位的序列: 11000101 10000010 00000001.
 * 
 * 返回 true 。
 * 这是有效的 utf-8 编码，为一个2字节字符，跟着一个1字节字符。
 * 
 * 
 * 示例 2:
 * 
 * 
 * data = [235, 140, 4], 表示 8 位的序列: 11101011 10001100 00000100.
 * 
 * 返回 false 。
 * 前 3 位都是 1 ，第 4 位为 0 表示它是一个3字节字符。
 * 下一个字节是开头为 10 的延续字节，这是正确的。
 * 但第二个延续字节不以 10 开头，所以是不符合规则的。
 * 
 * 
 */

