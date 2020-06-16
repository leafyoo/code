// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0;
        if(n < 2) 
            return n;

        vector<int> l(n, 1), r(n, 1) ;

        //从左往右找不服气的，分数更低引起的不平衡不考虑！（因为可能导致负数），“评分高的孩子必须获得更多的糖果。”
        for( int i = 1; i < n; ++i)                    
        {
            if(ratings[i] > ratings[i-1])
               l[i] = l[i-1] + 1;
        }
        for( int i = n-2; i >= 0; --i)                  //从右往左找不服气的，
        {
            if(ratings[i] > ratings[i+1])
               r[i] = r[i+1] + 1;
        }
        
        for( int i = 0; i < n; ++i)                     
            res += max( l[i], r[i]);     //取最大值为该位置的最终结果

        return res;
    }
};
// @lc code=end

/* 
https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/

 */

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (41.62%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 38.6K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 示例 1:
 * 
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 
 */
