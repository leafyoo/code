// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int res = n;        //注意：这里先初始化为n了，因为实际的数字少一个
        for( int i = 0; i < n; ++i)
        {
            res = res ^ (nums[i]) ^ i;
        }
        return res;
    }
};
/* fish:异或运算，很简单啊
https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-leetcode/

异或运算， 二进制位逐个比较，相同的为0， 不同的为1。
所以任一数字，异或自己 肯定等于 0。 此外异或运算满足 交换律 A^B^C = A^C^B
好，来分析题目，题中数组为 0~n 中缺失一个数字。那么加上数组的下标。用异或刚好可以得出缺失的数字。
如： [3, 0, 1]
可得：3^0^1^0^1^2^3 = 2

missing
=4∧(0∧0)∧(1∧1)∧(2∧3)∧(3∧4)
=(4∧4)∧(0∧0)∧(1∧1)∧(3∧3)∧2
=0∧0∧0∧0∧2
=2

 */


class Solution_math {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return (nums[0] == 0 ? 1 : 0 );

        long long sum = (n+1) * 0.5 * (0 + (double)n);             //错误：这里是n+1，因为是n+1个数
        long long trueSum = accumulate(nums.begin(), nums.end(), 0);
        
        return sum - trueSum;           //期望和 - 实际和 == 缺失的数
    }
};
/* fish: 注意：这个方法虽然通过了，但是求和有溢出风险！！！ */


// @lc code=end

/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (54.73%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    56.3K
 * Total Submissions: 102.7K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */

