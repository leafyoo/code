// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res; 
        vector<int> last;  

        for( int i = 0; i < numRows; ++i)
        {
            vector<int> v;

            if(i >= 0) 
                v.push_back( 1 );
            
            for( int j = 1; j < i; ++j)
            {
                v.push_back( last[j - 1] + last[j] );
            }

            if(i >= 1) 
                v.push_back( 1 );

            last = v;
            res.push_back( v );
        }     

        return res;          
    }
};
// @lc code=end
/* 
fish:写成下面的形式，一目了然：
    [1],
 * ⁠ [1,1],
 * ⁠ [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠ [1,4,6,4,1]
 * ]
 */

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (65.64%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    59.8K
 * Total Submissions: 91K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
