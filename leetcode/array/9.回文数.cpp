
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;     //这里return之后，下文就肯定是正数了，必然这里先return

        long long n = 0;
        for( int i = x; i ; i /= 10)
            n = n * 10 + i % 10;

        return (n == x);                    //错误：因为上面没有用i来循环而用x，导致x最终为0，从而这里为false了。
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.08%)
 * Likes:    949
 * Dislikes: 0
 * Total Accepted:    254.9K
 * Total Submissions: 446.4K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */
