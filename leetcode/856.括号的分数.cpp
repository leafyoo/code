// @lc code=start
class Solution_not_stack {
public:
    int scoreOfParentheses(string S) {
        int n = S.size();

        int times = 1, sum = 0;
        for( int i = 0; i < n; ++i)
        {
            if ( S[i] == '(' )
            {
                times *= 2;
            }
            else
            {
                times /= 2;
                if( i-1 >= 0 && S[i-1] == '(' )
                {
                    sum += times * 1;
                }
            }
        }

        return sum;
    }
};

//leetcode官方：栈
class Solution {
public:
    int scoreOfParentheses(string S) {
        int n = S.size();
        stack<int > st;
        st.push( 0 );
        for( int i = 0; i < n; ++i)
        {
            if ( S[i] == '(' )
                st.push( 0 );
            else
            {
                int top1 = 0, top2 = 0;
                if(!st.empty())
                {
                    top1 = st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    top2 = st.top();
                    st.pop();
                }
                top1 = top2 + (top1 != 0 ? (2 * top1) : 1);     //将当前深度的得分乘二并加到上一层的深度。fish：这里有点像内存的伙伴算法，或者是二进制进位换算
                st.push( top1 );
            }
        }
        return st.top();
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 *
 * https://leetcode-cn.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (57.66%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 8.5K
 * Testcase Example:  '"()"'
 *
 * 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
 * 
 * 
 * () 得 1 分。
 * AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
 * (A) 得 2 * A 分，其中 A 是平衡括号字符串。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： "()"
 * 输出： 1
 * 
 * 
 * 示例 2：
 * 
 * 输入： "(())"
 * 输出： 2
 * 
 * 
 * 示例 3：
 * 
 * 输入： "()()"
 * 输出： 2
 * 
 * 
 * 示例 4：
 * 
 * 输入： "(()(()))"
 * 输出： 6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S 是平衡括号字符串，且只含有 ( 和 ) 。
 * 2 <= S.length <= 50
 * 
 * 
 */