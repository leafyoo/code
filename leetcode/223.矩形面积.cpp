// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (D - B) * (C - A);
        int s2 = (H - F) * (G - E);
        if(B >= H || F >= D || G <= A || E >= C)
            return s1 + s2;
        
        int begX = max(A, E);       //错误：这里错写成了min
        int begY = max(B, F);
        int endX = min(C, G);
        int endY = min(D, H);
        int comS = (endX - begX) * (endY - begY);

        return s1 + (s2 - comS);        //错误：这里溢出了，所以要 先减后加
    }
};
// @lc code=end
/* fish
https://leetcode-cn.com/problems/rectangle-area/solution/223-ju-xing-mian-ji-wu-tao-lu-chun-bao-li-java-by-/
 */

/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 *
 * https://leetcode-cn.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (42.68%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 19.4K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
 * 
 * 每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: -3, 0, 3, 4, 0, -1, 9, 2
 * 输出: 45
 * 
 * 说明: 假设矩形面积不会超出 int 的范围。
 * 
 */

