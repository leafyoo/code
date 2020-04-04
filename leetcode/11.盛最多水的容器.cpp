
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int b = 0, e = height.size() - 1;
        int water = 0;
        while( b < e )
        {
            int h = min(height[b], height[e]);
            water = max(water, h * (e - b));

            while(b < e && height[b] <= h) ++b;
            while(b < e && height[e] <= h) --e;
        }
        return water;
    }
};
// @lc code=end
/* 
fish:
1、从中间没有头绪，那就从两边着手！
2、注意内部的两个while 循环，这里的b < e
3、找到突破点：每次收缩边界会消去一个解，我们要确保被消去的这个解不会是我们的目标（最大面积），
那只能将短板往里收缩，这样移动一步之后，里头的柱子才可能更高，才可能遇到更大的面积

【举例】！！！：例如对于 : 1， 3， 2， 怎么移动呢？（b=1 e=2）， 肯定是移动更短的b，使得b=3啊

 */
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (61.27%)
 * Likes:    1133
 * Dislikes: 0
 * Total Accepted:    140.8K
 * Total Submissions: 229.4K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */

