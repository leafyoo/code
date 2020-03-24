// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int b = 1, e = x;
        long long m = 0;
        while( b <= e )
        {
            m = ((long long)b + (long long)e)/2;                //错误：这里要有 (long long)强转
            long long mult = (long long)m * (long long)m;       //错误：这里要有 (long long)强转
            if(mult == x)
                return m;
            else if( mult < x )
                b = m+1;
            else
                e = m-1;
        }
        return (m * m > x) ? m-1 : m;       //处理平方根为小数的情况
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.53%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    107.4K
 * Total Submissions: 285.6K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */
