// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        
        stack<char> st;
        unordered_map<char, char> mp{ 
            {')', '('}, 
            {'}', '{'}, 
            {']', '['} };                   //错误：unordered 少了 ed

        for( int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push( s[i] );
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(st.empty() || st.top() != mp[ s[i] ])                //注意：这里要判断st.top()
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.85%)
 * Likes:    1401
 * Dislikes: 0
 * Total Accepted:    209.7K
 * Total Submissions: 512.4K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
