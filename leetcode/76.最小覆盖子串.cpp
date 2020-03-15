// @lc code=resBeg
class Solution {
public:
    string minWindow(string s, string t) {
        int resBeg = 0, resLen = INT_MAX;
        unordered_map<char, int> windowMap, tmap;

        for (int i = 0; i < t.size(); i++) 
            ++tmap[ t[i] ];                         //这里++ ，不是=1，因为可能t里有多个重复的字符
        
        int beg = 0, end = 0, match = 0;

        //end指针从左往右增加
        while( end < s.size() )
        {
            //1：找最大串
            while (end < s.size() && match != tmap.size()) 
            {
                char  ec  = s[end];
                if (tmap.count( ec ) > 0)               //如果 是需要匹配的char， 更新windowMap、match
                {
                    windowMap[ ec ]++;
                    if (windowMap[ ec ] == tmap[ ec ]) 
                        match++;
                }
                ++end;
            }

            //2：找最小串。这里陷入处理最大串，缩小为最小串。外循环多次后，终于找到了最大串。
            while (beg <= end && match == tmap.size())            //区间[beg, end]内包含了所有目标字符。 这里只能是tmap.size()，相当于对t去重了
            {
                if (end - beg < resLen)             //更新最小串
                {
                    resBeg = beg;
                    resLen = end - beg;
                }

                char  bc = s[beg];
                if (tmap.count( bc) > 0)          //如果 是需要匹配的char
                {
                    windowMap[ bc]--;
                    if (windowMap[ bc] < tmap[ bc]) 
                        match--;
                }
                ++beg;
            }
        }
       
        return (resLen == INT_MAX) ? "" : s.substr(resBeg, resLen);
    }
};
/* 
fish：
整体思路，滑动窗口：
1、外循环找到最大满足串；（++end）
2、内循环陷入最大串缩小串的规模为最小。（++beg）

 */

// @lc code=end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-windowMap-substring/description/
 *
 * algorithms
 * Hard (35.38%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 76.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */
