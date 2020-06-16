// @lc code=start
class Solution {
public:
    string decodeString(string s) 
    {
        int n = s.size();
        if(n < 1) 
            return "";

        int mul = 0;
        string res;

        stack<int>      stMul;
        stack<string>   stRes;
        
        for( int i = 0; i < n; ++i)
        {
            if(s[i] >= '0' && s[i] <= '9')              //错误：这里写成了 ||
                mul = mul * 10 + s[i] - '0';
            else if( s[i] == '[')
            {
                stMul.push( mul);
                stRes.push( res);           //因为可能有多重'['，所以要push到栈里
                
                mul = 0;
                res = "";
            }
            else if( s[i] == ']')
            {
                string tmp;
                for( int i = 0; i < stMul.top(); ++i)
                    tmp += res;

                res = stRes.top() + tmp;

                stMul.pop();
                stRes.pop();
            }
            else
                res += s[i];
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode-cn.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (49.32%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 44.1K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 
 * 示例:
 * 
 * 
 * s = "3[a]2[bc]", 返回 "aaabcbc".
 * s = "3[a2[c]]", 返回 "accaccacc".
 * s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 * 
 * 
 */
