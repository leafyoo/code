// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        if(!na || !nb) return 0;

        int res = 0;

        //dp[i][j]含义：A的i之前部分 与 B的j之前部分 相同子串的长度
        vector<vector<int> > dp (na+1, vector<int>(nb+1, 0));

        for( int i = 1; i <= na; ++i)
        {
            for( int j = 1; j <= nb; ++j)
            {
                if(A[i-1] == B[j-1])        //当前值相等，数组的下标比dp下标小1
                {
                    dp[i][j] = dp[i-1][j-1] + 1;    //dp[i-1][j-1] ： 左上方那个点的匹配情况
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};
// @lc code=end

/*
【相似】和516题不一样，516题是单个输入内部的长度，此题是两个输入之间的比较

fish：不要一味追求别致，稳当最重要，这道题按照下面的解法，陷入了大坑。按照动态规划容易很多。
 * A: [1,2,3,2,1]
 * B:     [3,2,1,4,7]
 * 
 * 
 矩阵图：
 https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/dong-tai-gui-hua-by-hai-gen/
 */


/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (48.58%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 18.5K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出: 3
 * 解释: 
 * 长度最长的公共子数组是 [3, 2, 1]。
 * 
 * 
 * 说明:
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */


/*
错误：未通过：太复杂

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        if(!na || !nb) return 0;

        map<int, set<int> > mp;                 //map ， key：数值， value：这个数值在A中哪些位置有出现过
        for( int i = 0; i < na; ++i)
            mp[A[i]].insert(i);
        int maxLen  = 0;

        set<int> stNextIdxInA;
        for( int i = 0, len = 0; i < nb; ++i)
        {
            if(mp.find( B[i] ) == mp.end() )     //当前无相等
            {
                len = 0;
                stNextIdxInA.clear();
            }
            else 
            {
                if(stNextIdxInA.empty())
                {//第一次有相等
                    for( set<int>::iterator it = mp[ B[i] ].begin(); it != mp[ B[i] ].end(); ++it)
                    {
                        if(*it + 1 < na)
                            stNextIdxInA.insert( *it + 1);      //记录下一次在A中期望的下标集合
                    }
                    len = 1;
                }
                else
                {//第n次有相等

                    //求期望下标集合、实际查到的下标集合的交集。同时缩小期望下标集合的规模
                    for( set<int>::iterator it = stNextIdxInA.begin(); it != stNextIdxInA.end(); )
                    {
                        if(mp[ B[i] ].find(*it) == mp[ B[i] ].end())
                            it = stNextIdxInA.erase(it);
                        else
                            ++it;
                    }
                    
                    if(stNextIdxInA.empty())        //不符合期望
                    {
                        len = 0;
                        stNextIdxInA.clear();
                    }
                    else
                    {
                        ++len;
                        maxLen = max(maxLen, len);
                    }
                }

            }
        }

        return maxLen;
    }
};


 */