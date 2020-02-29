
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() < 2) return ;

        int row = matrix.size(), col = matrix[0].size();
        for( int i = 0; i < row/2; ++i)
        {
            for( int j = 0; j < col; ++j)
            {
                swap(matrix[i][j] , matrix[row-1-i][j]);
            }
        }

        for( int i = 0; i < row; ++i)
        {
            for( int j = i+1; j < col; ++j)
            {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }
};
// @lc code=end
/*
fish:
思路：先按行镜像，之后按主对角线镜像

1,2,3    7,8,9    7,4,1
4,5,6 => 4,5,6 => 8,5,2 
7,8,9    1,2,3    9,6,3

(1)swap row i and row n-1-i
(2)swap elements in symmetrical position


*/



/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (66.86%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    55.8K
 * Total Submissions: 83.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * 
 * 示例 1:
 * 
 * 给定 matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 给定 matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
