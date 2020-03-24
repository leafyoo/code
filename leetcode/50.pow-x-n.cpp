// @lc code=start
class Solution {
public:
    double pow(double x, int N) {
        if(N == 0) return 1.0;

        double half = pow(x, N/2);
        if(N % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;

        if(N == 0)  return 1.0;
        if(N < 0)
        {
            x = 1/x;
            N = -N;             //错误： n = -n;   对n直接取负值，int溢出了！！
        }

        return pow(x, N);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (34.18%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    60.5K
 * Total Submissions: 176.9K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */