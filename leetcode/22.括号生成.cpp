// @lc code=start
class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        DFS("", n, n);
        return res;
    }

    //left   左括号还有几个可以使用
    void DFS(string str, int left, int right)
    {
        if(left > right)    //剩余左括号数量大于右括号数量。为什么？因为字符串必须是以左括号开头,所以占用了一个
            return ;

        if ( !left && !right )
            res.push_back(str);

        if( left > 0 )
            DFS(str + "(", left-1, right);
        if( right > 0 )
            DFS(str + ")", left, right-1);
    }

};
// @lc code=end
/* 
    * @param curStr 当前递归得到的结果
    * @param left   左括号还有几个可以使用
    * @param right  右括号还有几个可以使用
    * @param res    结果集
    *
第一位必须是左括号，最后一位必须是右括号，开始情况只有两种：（（...和（）（...，不可能是（））（等等，然后排列组合（只有两种情况）安排进去就OK了，

链接：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/

 */


/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.31%)
 * Likes:    796
 * Dislikes: 0
 * Total Accepted:    85.3K
 * Total Submissions: 115.9K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
