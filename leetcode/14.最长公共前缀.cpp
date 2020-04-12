// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty()) return res;
        if(strs.size() == 1) return strs[0];

        for( int i = 0; i < strs[0].size(); ++i)
        {
            for( vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
            {
                if ( (*it).size() < (i+1) || strs[0][i] != (*it)[i] )
                    return res;
            }

            res += strs[0][i];
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.15%)
 * Likes:    892
 * Dislikes: 0
 * Total Accepted:    192.2K
 * Total Submissions: 529.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */