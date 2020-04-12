// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n < 1) return s;
        
        //处理头尾空格
        int b = 0, e = n - 1;
        while( b < n && s[b] == ' ') ++b;
        while( e >= 0 && s[e] == ' ') --e;
        if(e < b) return "";

        s = s.substr( b, e - b + 1 );

        //处理中间空格
        int spaceRmCnt = 0;
        for( int i = 0, j = 0; i < s.size() && j < s.size(); )
        {
            while( j < s.size() && i < s.size() && s[j] != ' ') s[i++] = s[j++];
            while( j < s.size() && s[j] == ' ') ++j;  
            if(j < s.size() && i < s.size())
                s[i++] = ' ';
            spaceRmCnt = j - i;
        }

        //去掉尾部多余的部分字母， 这里类似于stl里的remove，尾部字母还在的！
        s = s.substr(0, s.size() - spaceRmCnt); //错误：这里 s.size()写成了 n，s经过上面的处理，大小早已经变了！！！

        reverse(s.begin(), s.end());

        for( int b = 0; b < s.size(); )         //错误：这里多了一个++b！！再次犯错 
        {
            int e = b;
            while( e < s.size() && s[e] != ' ' ) ++e;

            reverse( s.begin()+b, s.begin()+e );
            
            while( e < s.size() && s[e] == ' ' ) ++e;
            b = e;
        }

        return s;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (36.84%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    36.9K
 * Total Submissions: 99.7K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */

