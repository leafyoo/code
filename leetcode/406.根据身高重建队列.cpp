// @lc code=start
class Solution {
public:
    static bool comp( const vector<int> & a, const vector<int> & b)     //错误：少了 static. Char 49: error: invalid use of non-static
    {
        return ( (a[0] == b[0] ) ? (a[1] < b[1]) : (a[0] > b[0]) );
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if(people.empty() || people[0].empty()) return res;
        
        sort(people.begin(), people.end(), comp );

        for( int i = 0; i < people.size(); ++i)
        {
            res.insert(res.begin() + people[i][1], people[i] );
        }

        return res;
    }
};
/* 
fish:完全没必要：下面Solution_list版本性能也只是好了一点点而已，占用内存反而多了，完全没必要
37/37 cases passed (72 ms)
Your runtime beats 87.97 % of cpp submissions
Your memory usage beats 31.2 % of cpp submissions (13.1 MB)
 */


class Solution_list {
public:
    static bool comp( const vector<int> & a, const vector<int> & b)     //错误：少了 static. Char 49: error: invalid use of non-static
    {
        return ( (a[0] == b[0] ) ? (a[1] < b[1]) : (a[0] > b[0]) );
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if(people.empty() || people[0].empty()) return res;
        sort(people.begin(), people.end(), comp );

        list<vector<int> > lst;                                 //list适合随机插入，先用list来组装
        for( int i = 0; i < people.size(); ++i)
        {
            list<vector<int> >::iterator it = lst.begin();
            advance(it, people[i][1]);
            lst.insert(it, people[i] );
        }
        res.assign(lst.begin(), lst.end() );

        return res;
    }
};
// @lc code=end
/* 
37/37 cases passed (44 ms)
Your runtime beats 94.26 % of cpp submissions
Your memory usage beats 25.39 % of cpp submissions (14.1 MB)
 */


/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (62.22%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    19.1K
 * Total Submissions: 30.3K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 * 
 * 注意：
 * 总人数少于1100人。
 * 
 * 示例
 * 
 * 
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */
