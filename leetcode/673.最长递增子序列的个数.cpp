// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        
        vector<int> len(n, 1);              // len[i]: 以nums[i]结尾的LIS的长度
        vector<int> cnt(n, 1);              // cnt[i]: 以nums[i]结尾的LIS的数量
        
        for (int i = 1; i < n; ++i)         //循环，找出以 i 下标为LIS的相关统计数据（即：下文中的目的是更新上面的len[i]、cnt[i]， j只是个游标）
        {
            for (int j = 0; j < i ; ++j) 
            {
                if (nums[j] < nums[i])                      //因为研究的是以nums[i]结尾（确定的）的LIS，所以nums[j] 大于等于nums[i]的情况无需关注
                {
                    if (len[j] >= len[i] )                  
                    {
                        len[i] = len[j]+1;                  //这里的+1 为 nums[i]自己
                        cnt[i] = cnt[j];                    //则替换，以以nums[j]为结尾的LIS的数量为准
                    }
                    else if (len[j]+1 == len[i])            //nums[i]可以直接追加在nums[j]之后，长的LIS长度一样，所以也要算在cnt[i]里8
                    {
                        cnt[i] += cnt[j];
                    }           
                                                            //这里剩下len[j]+1 < len[i]的情况，无需关注
                }
            }        
        }
        
        int maxLen = *max_element(len.begin(), len.end());
        
        int cnt_maxLen = 0;
        for (int i = 0; i < n; ++i)
            if (len[i] == maxLen) cnt_maxLen += cnt[i];
        
        return cnt_maxLen;        
    }
};
// @lc code=end
/*
fish:
【相似：上升子序列】 同 [300] 最长上升子序列

1。【总结】动态规划使用到的dp数组有这几种情况：二维矩阵的dp（空间O（n2）），双数组（空间O（n）），单数组（空间O（n））。
2。 这里两个循环，外循环i先统计过了，内循环j始终是重新统计那些统计过的范围内（比i小）的，所以j的相关数据是可靠的，无需更新的。
所以我们的目标是以可靠的历史数据j，来更新下一步的i的统计数据。如此循环。

*/


/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (34.09%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 16.2K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * 
 */
