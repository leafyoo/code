// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        map<int, int> mp;
        for( int i = 0; i < A.size(); ++i)
        {
            for( int j = 0; j < B.size(); ++j)
            {
                ++mp[ A[i] + B[j] ];
            }
        }

        for( int i = 0; i < C.size(); ++i)
        {
            for( int j = 0; j < D.size(); ++j)
            {
                map<int, int>::iterator it = mp.find( -(C[i] + D[j]) );     //注意：不能用mp[]这样
                res += ( ( it == mp.end()) ? 0 : it->second );
            }
        }
        return res;
    }
};
// @lc code=end
/* 
fish:

思路:
其实就是两数之和的扩展版

没啥好说的，遍历前两个数组可以相加得到所有值的个数，然后再遍历后两个数组，即可

时间复杂度O(n^2) */


/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 *
 * https://leetcode-cn.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (54.30%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    18.8K
 * Total Submissions: 34.5K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] +
 * D[l] = 0。
 * 
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1
 * 之间，最终结果不会超过 2^31 - 1 。
 * 
 * 例如:
 * 
 * 
 * 输入:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * 
 * 输出:
 * 2
 * 
 * 解释:
 * 两个元组如下:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 * 
 * 
 */

