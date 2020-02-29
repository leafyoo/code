
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        while( x != 0 )
        {
            res = res * 10 + x % 10;
            x /= 10; 
        }

        res = (res < INT_MIN || res > INT_MAX) ? 0 : res;       //错误：注意仔细审题，处理溢出情况

        return (int)(res);
    }
};
// @lc code=end

/*
fish:

*/


/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.63%)
 * Likes:    1705
 * Dislikes: 0
 * Total Accepted:    280.8K
 * Total Submissions: 833.9K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
