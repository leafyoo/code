// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;

        int ti = 0, si = 0;
        for( ; ti < t.size() && si < s.size(); )           //注意：这里用ti、si ： t index， s index，直观，不用大脑转弯
        {
            if(s[si] == t[ti])
            {
                if(si == s.size() - 1)                      //注意：这里把s、n理解反了！！！  不能思维定式而觉得那个参数是pattern！！
                    return true;                            //技巧：循环内部判断来终止程序，会简化逻辑，在末尾处理时情况会很多。

                ++si, ++ti;
            }
            else
                ++ti;
        }

        return false;
    }
};

class Solution_dp {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;

        int sn = s.size(), tn = t.size();
        vector<int> dp(sn, -1);                     //错误：此题把s、n理解反了！！！  不能思维定式而觉得那个参数是pattern！！

        for (int i = 0; i < sn; ++i)
        {
            int beg = (i-1 >= 0) ? dp[i-1]+1 : 0;
            for (int j = beg; j < tn; ++j)     
            {
                if (s[i] == t[j])
                {
                    dp[i] = j;
                    break;
                }
            }
            if(dp[i] == -1)                         //错误：这里任何一个字母找到末尾都没有找到，则需要return
                return false;
        }

        return true;
    }
};
// @lc code=end
/*
fish:

// return dp[tn-1] != -1;              //错误：这里写成了  == 

*/

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 *
 * https://leetcode-cn.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (47.84%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    26.2K
 * Total Submissions: 54.6K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 示例 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 返回 true.
 * 
 * 示例 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 返回 false.
 * 
 * 后续挑战 :
 * 
 * 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 * 
 * 致谢:
 * 
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 * 
 */
