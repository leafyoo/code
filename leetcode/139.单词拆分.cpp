
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) 
            return true;

        int n = s.size();
        vector<bool> dp(n, false);      //dp[i] 表示 下标区间为 [0 , i]的部分都包含在dict里 
        
        //0...i 这一段构成整个字符串
        for( int i = 0; i < n; ++i)     //1、从头部开始，处理不能被细分的情况，也就是不用 j 游标来循环判断的
        {
            if(wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(0, i+1)))  //错误：不可以用 s[0]，是char
                dp[i] = true;
        }
        
        // [0 ... j], [j+1 ... i] ... n
        //将 [0 ... i]拆分成2部分看
        for( int i = 0; i < n; ++i)     //2、从头部开始，处理可以进一步细分的情况
        {
            for( int j = 0; j < i; ++j)             //这里的边界条件根据下文来确定
            {
                //当前字符(j)以及之前的部分包含在dict里（区间为：[0 , j] ）  &&  下一个字符到i之间的部分（区间为：[j+1 , i] ）包含在dict里

                if ( dp[j] && wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(j+1, i-j)))
                {
                    dp[i] = true;       //dp是一维的，只需要计算出每一个dp[i]就可以暂停了
                    break;
                }
            }
        }

        return dp[n-1];
    }
};
// @lc code=end
/*
fish:

*/

/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;

        int n = s.size();
        vector<bool> dp(n + 1);         //dp[i] 表示下标为i-1的字符（包含）以及前面的字符的所有字符串是否包含在dict里
        dp[0] = true;

        for( int i = 1; i <= n; ++i)    //考察下标为i-1处以及之前的部分的字符，因为这里是dp的下标，不是s的下标
        {
            for( int j = 0; j < i; ++j)
            {
                //前一个字符以及之前的字符串都包含在dict  &&  当前字符(j)到i-1之间的部分包含在dict里
                if ( dp[j] && wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)))
                {
                    dp[i] = true;           //下标为i-1以及之前的部分包含在dict里
                    break;
                }
            }
        }
        return dp[n];                       
    }
};*/


/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (43.20%)
 * Likes:    328
 * Dislikes: 0
 * Total Accepted:    36.4K
 * Total Submissions: 83.6K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */


/*
fish:
失败：
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;

        int n = s.size();
        vector<bool> dp(n, false);

        if( wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(0,1 ) ) )      //错误：不可以用 s[0]，是char
            dp[0] = true;

        for( int i = 1; i < n; ++i)
        {
            for( int j = 0; j < i; ++j)             //这里的边界条件根据下文来确定
            {
                if(wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)))
                {
                    dp[i] = true;
                    break;                    
                }
                if ( dp[j] && wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(j+1, i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};

*/