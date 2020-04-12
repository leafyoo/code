// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end() ), st2;
        
        for( int i = 0; i < nums2.size(); ++i)
        {
            if(st.find(nums2[i]) != st.end())
                st2.insert( nums2[i]);                  //错误：这里不能用vector，会有重复数据，不满足题目要求
        }

        return vector<int>(st2.begin(), st2.end());
    }
};



//高效版
class Solution_better {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end() );
        vector<int> res;

        for( int i = 0; i < nums2.size(); ++i)
        {
            if( st.erase( nums2[i] ))     //删除2个作用：1.避免后面在set里重复查询； 2.避免下面的vector重复插入相同的元素。
                res.push_back( nums2[i]);
        }
        return res;
    }
};
/* 
fish：
题目简单，就一定要有高效率方案才行！

知识点：表示成功删除的元素个数
//删除 set 容器中值为 val 的元素
size_type erase (const value_type& val);
 */


// @lc code=end

/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.16%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    54.9K
 * Total Submissions: 80.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
