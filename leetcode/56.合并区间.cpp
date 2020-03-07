
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;

        multimap<int, int> mp;                                               //因为可能 多个区间的开始位置相等，所以这里要用multimap
        vector<vector<int> > vec;
        for( vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); ++it)
        {
            mp.insert(make_pair( (*it)[0]  , (*it)[1]));                    //这里注意只能用这种插入方法。
        }

        int b = mp.begin()->first, e = mp.begin()->second;                  //错误：这里不该用e = intervals[0][1]; 因为intervals还没有排序
        for( map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->first <= e) 
                e = max(e, it->second);
            else
            {
                vec.push_back( {b, e} );    

                b = it->first;
                e = it->second;
            }
        }

        vec.push_back( {b, e} );      

        return vec;
    }
};
// @lc code=end

/* fish：时间复杂度： O(n * lgn)
1、插入一个节点到红黑树的时间为：O(lgn)
则创建一颗红黑树的时间复杂度：n * O(lgn) =  O(n * lgn)

遍历红黑树复杂度：O(n)
所以总体时间复杂度为：O(n * lgn)

2、fish：注意vector的构造方法：{b, e} 等效于
        vector<int> v;
        v.push_back(b);    
        v.push_back(e);

 */
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.29%)
 * Likes:    288
 * Dislikes: 0
 * Total Accepted:    53.9K
 * Total Submissions: 133.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
