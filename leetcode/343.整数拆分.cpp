// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;

        if((n % 3) == 0) 
            return (int)pow(3, (n / 3) );
        
        else if((n % 3) == 1) 
            return (int)pow(3, (n / 3) - 1 ) * (2 * 2); //当 = 1 时，要将一个 1+3 转换为 2+2

        else if((n % 3) == 2)
            return (int)pow(3, (n / 3)) * 2; 
        
        return -1;
    }
};
// @lc code=end
/* fish

推论一： 若拆分的数量 a 确定， 则 各拆分数字相等时 ，乘积最大。

推论二： 将数字 n尽可能以因子 3 等分时，乘积最大。

拆分规则：
最优： 3 。把数字 n可能拆为多个因子 3 ，余数可能为 0,1,2  三种情况。
次优： 2 。若余数为 2 ；则保留，不再拆为 1+1  。
最差： 1 。若余数为 1 ；则应把一份 3 + 1  替换为 2 + 2 ，因为 2 \times 2 > 3 \times 12×2>3×1。

作者：jyd
链接：https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */


/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (55.19%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    23.2K
 * Total Submissions: 41.8K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

