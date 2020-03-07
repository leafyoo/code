// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n < 1) return 0;

        vector<int> left(n, -1);        //给左边界都初始化为最小 -1
        for( int i = 1, j ; i < n; ++i)
        {
            for( j = i-1; j >=0 && heights[j] >= heights[i]; )      //错误：这里少了j = i-1，而是放在了上一级循环i里，导致j每一轮得不到更新
                j = left[j];
            left[i] = j;
        }

        vector<int> right(n, n);        //给右边界都初始化为最大 +1
        for( int i = n-2, j ; i >= 0; --i)
        {
            for( j = i+1; j < n && heights[j] >= heights[i]; )
                j = right[j];
            right[i] = j;
        }

        int res = 0;                    //循环，取最大面积
        for( int i = 0; i < n; ++i)     
            res = max(res, heights[i] * (right[i] - left[i] - 1));      

        return res;
    }

};

class Solution_force {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n < 1) return 0;

        int res = INT_MIN;
        for( int i = 0; i < n; ++i)     //错误：j和i要相同开始，否则比如[0, 9]这种单柱形就不能覆盖到，不要想当然觉得j和i隔开！！！一定要质疑问可不可以
        {
            int h = heights[i];
            for( int j = i; j >= 0; --j)        //因为是面积，所以j从i这里，从近往远走，这样的话，j永远都是基于走过的路来走，知道到i之间的min
            {
                h = min( h, heights[j] );
                res = max(res, h * (i-j+1) );
            }
        }

        return res;
    }
};
// @lc code=end

/* 
fish:
class Solution:
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-7/

fish自述思路：
（1）首先，这个最大面积，一定是以所有柱子z中其中之一作为高h的，
而且，一定是以这个柱子z为高可以画出的最大的矩形面积（高度不能超过柱子z也不能低于z）。
(2)好了，那现在我们要做的就是，先找出每一个以当前柱子为高的最大面积，然后比较所有面积取最大值。
(3)回到（1），我们要找出柱子z往左右两边拓展时的边界，这个边界就是左右两边比z小的柱子。


class Solution_force :
错误case 1:
[0, 9]

错误case 2:
Time Limit Exceeded
6万个1


 */

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (38.69%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 78.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */
