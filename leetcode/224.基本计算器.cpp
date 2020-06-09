// @lc code=start
class Solution {
public:
    int calculate(string s) {
        
        stack<int> stkSign;
        stack<int> stk;

        int res = 0, n = s.size(), sign = 1;
        for(int i=0; i<n; i++) 
        {
            if(s[i] >= '0')                     //正常运算
            {
                int num = 0;
                while(i<n && s[i] >= '0') 
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;        //因为for主循环已经有i++，这里要回退1
                res += sign * num;
            }
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '(')                //压栈
            {
                stkSign.push(sign);
                stk.push(res);

                res = 0;        //reset  //【知识点】 上面已经存到栈里了，这里就没用了，可以清空了
                sign = 1;
            }
            else if(s[i] == ')')                //出栈
            {
                res *= stkSign.top();           //先处理 符号
                stkSign.pop();
                
                res += stk.top(); 
                stk.pop();
            }
        }

        return res;
    }
};

// @lc code=end


/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (37.04%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 30.6K
 * Testcase Example:  '"1 + 1"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
 * 
 * 示例 1:
 * 
 * 输入: "1 + 1"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 2-1 + 2 "
 * 输出: 3
 * 
 * 示例 3:
 * 
 * 输入: "(1+(4+5+2)-3)+(6+8)"
 * 输出: 23
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */
