// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};//特殊情况直接排除
        vector<int> res; 
        
        //单词数组中的单词的大小，个数，以及总长度
        int wordLen=words[0].size();
        int wordCnt = words.size();
        int TotalLen = wordLen*wordCnt;
        
        unordered_map<string,int> mapWordCnt;   //建立单词->单词个数的映射
        for(const auto& w:words) mapWordCnt[w]++;
        
        for(int i = 0;i<wordLen;++i)
        {
            int beg = i, end = i, match = 0;       //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            unordered_map<string,int> mapWindow;
            while(end+wordLen<=s.size())                 //开始滑动窗口
            {
                string curWord = s.substr(end,wordLen);        //从s中提取一个单词拷贝到w
                end += wordLen;                            //窗口右边界右移一个单词的长度
                
                if(mapWordCnt.count(curWord) == 0)
                {                           //此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                    match = 0;
                    beg = end;
                    mapWindow.clear();
                }
                else
                {                           //该单词匹配成功，添加到map
                    mapWindow[curWord]++;
                    match++;    
                    while(mapWindow[curWord] > mapWordCnt[curWord] )//一个单词匹配多次，需要缩小窗口，也就是left右移
                    {
                        match--;
                        mapWindow[ s.substr(beg, wordLen) ]--;
                        beg += wordLen;
                    }
                    if(match == wordCnt)
                        res.push_back(beg);
                }
            }
        }
        return res;
    }
};


// @lc code=end

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (29.17%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 87K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */
