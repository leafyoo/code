// @lc code=start
class Solution_multimap {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty() || k < 1) 
            return vector<int>();

        unordered_map<int, int> mp;
        for( int i = 0; i < nums.size(); ++i)
            mp[ nums[i] ] ++;

        multimap<int, int, greater<int> > mpCntToKey;           //错误：这里没有multi，那会导致计数一样的key只能插入一个
        for( unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
            mpCntToKey.insert( make_pair(it->second, it->first ) );
        
        vector<int> res;
        for( multimap<int, int, greater<int> >::iterator it = mpCntToKey.begin(); 
            it != mpCntToKey.end() && res.size() < k; ++it)
        {
            res.push_back( it->second );
        }

        return res;
    }
};

//用优先级队列实现
class Solution {
public:

    //仿函数不是函数，是类！
    class Comp
    {
        public:
        bool operator()(pair<int,int> &a, pair<int,int> &b)
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty() || k < 1) 
            return vector<int>();

        unordered_map<int, int> mp;
        for( int i = 0; i < nums.size(); ++i)
            mp[ nums[i]]++;

        priority_queue< pair<int,int>, vector<pair<int, int> >, Comp > priQ;                //错误：这里Comp不可以是函数，只可以是类（仿函数）
        for( unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
            priQ.push( *it );
        
        vector<int> res;
        for( int i = 0; i < k; ++i)
        {
            res.push_back( priQ.top().first );
            priQ.pop();
        }

        return res;
    }
};


/* class Solution_priority_queue {
public:
// 使用STL 优先队列
struct CmpByValueLess {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {

    //统计次数
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
        ++m[nums.at(i)];

    //注意：使用STL的优先队列 priority_queue  Comparator = greater 为小堆；Comparator = less 为大堆   
    priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValueLess> queue;
    for (auto iter = m.begin(); iter != m.end(); ++iter)
        queue.push(*iter);

    vector<int> res(k);
    for (int i = 0; i < k; ++i)
    {
        res.at(i) = queue.top().first;
        queue.pop();
    }

    return res;
}
}; */
/* 
作者：eric-345
链接：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/c-shi-xian-by-eric-345/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

// @lc code=end

/* 
fish：注意：map调换key、value时，需要用multimap
multimap<int, int, greater<int> >  ：  greater<int> 使得按key降序排列

 */

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.19%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    40.9K
 * Total Submissions: 67.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 说明：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 
 * 
 */
