// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> lineH(col, 0);          //保存每一列的高度

        int area = 0;
        for( int i = 0; i < row; ++i)       //遍历所有坐标轴区域，取最大值。 x坐标轴从最高位置，每次循环下一一个单位
        {
            for( int j = 0; j < col; ++j)
                lineH[j] = ( matrix[i][j] == '1' ? (lineH[j] + 1) : 0 ) ;       //错误：这里matrix[i][j] == '0' 时，要完全清零 ！
            area = max( area, dealLevel( lineH ));
        }

        return area;
    }

    int dealLevel(vector<int> &lineH)
    {
        int n = lineH.size();
        if(!n) return 0;

        vector<int> left(n, -1);
        vector<int> right(n, n);
        for( int i = 0, j = 0; i < n; ++i)
        {
            for( j = i-1; j >=0 && lineH[j] >= lineH[i]; )
                j = left[j];
            left[i] = j;
        }

        for( int i = n-1, j=n-1; i >= 0; --i)
        {
            for( j = i+1; j < n && lineH[j] >= lineH[i]; )
                j = right[j];
            right[i] = j;
        }

        int area = 0;
        for( int i = 0; i < n; ++i)
            area = max(area, (lineH[i] * (right[i] - left[i] - 1)) );
        return area;
    }

};
// @lc code=end
/* 
fish:
66/66 cases passed (20 ms)
Your runtime beats 91.91 % of cpp submissions

题解：
参考下面这里的解法2：
https://leetcode-cn.com/problems/maximal-rectangle/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-8/



动态规划：
https://leetcode-cn.com/problems/maximal-rectangle/solution/geng-zhi-bai-yi-dian-de-dong-tai-gui-hua-by-vsym/
 */


/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (44.42%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 43.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */
