
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;

        int b = 1, e = height.size() -2;
        int maxb = 0, maxe = 0, sum = 0;
        while( b <= e )                 //错误：这里要有=，可以举例，例如 202 时，b = 1， e=1，但是是有雨水的
        {
            if ( height[b-1] <= height[e+1] )
            {
                maxb = max(maxb, height[b-1]);
                if(height[b] < maxb)
                    sum += (maxb - height[b]);         
                ++b;
            }
            else
            {
                maxe = max(maxe, height[e+1]);
                if(height[e] < maxe)
                    sum += (maxe - height[e]);
                --e;
            }
        }

        return sum;
    }
};
// @lc code=end
/*
fish：
1、sum += (maxb - height[b]); //因为上面( height[b-1] <= height[e+1] )，所以可以放心大胆的加雨水，因为最次也是最右边那根栅栏会挡住雨水不被流出。

2、题解：
https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/

*/


/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (48.52%)
 * Likes:    862
 * Dislikes: 0
 * Total Accepted:    54.3K
 * Total Submissions: 111.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
