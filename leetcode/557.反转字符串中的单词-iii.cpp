// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int b = 0; 
        while(b < n)                    //注意：技巧：避免用for循环，因为总是处理不好自增，导致多增，少增！！！
        {   
            int e = b;
            while( e < n && s[e] != ' ' ) ++e;
        
            reverse(s.begin() + b, s.begin() + e);
        
            while( e < n && s[e] == ' ' ) ++e;
            b = e;
        }

        return s;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (69.90%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 68.5K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */

