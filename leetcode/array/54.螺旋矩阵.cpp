// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if( matrix.empty() ) return res;

        int ib = 0, jb = 0;
        int ie= matrix.size() - 1, je = matrix[0].size() - 1 ;
        int i = 0, j = 0;

        while(ib <= ie && jb <= je)
        {
            for( j = jb; j <= je; ++j) res.push_back(matrix[ib][j] );           //错误，这里matrix 每次都会有一个参数固定，这里ib不可以是i！
            if(++ib > ie) break;

            for( i = ib; i <= ie; ++i) res.push_back(matrix[i][je] );
            if(--je < jb) break;

            for( j = je; j >= jb; --j) res.push_back(matrix[ie][j] );   
            if(--ie < ib) break;

            for( i = ie; i >= ib; --i) res.push_back(matrix[i][jb] );   
            if(++jb > je) break;
            
        }

        return res;
    }
};
// @lc code=end
/*
fish:
b: begin,  e:end
思路：
1、每一行是一个i，每一列是一个j。
2、每走一个边都走到头，这样就会有一个极值（ib ie  jb  je）得到削减，从而下一条边的起点也变了。

*/


/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (38.62%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    41.6K
 * Total Submissions: 107.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */