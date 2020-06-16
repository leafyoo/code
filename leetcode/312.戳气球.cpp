// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) 
            return 0;

        int nold= nums.size();
        nums.insert(nums.begin(), 1);           //插入辅助元素
        nums.push_back(1);

        int nnew = nums.size();     //塞进去新的元素之后，变大了，不是nold了

        vector<vector<int> > dp (nnew, vector<int>(nnew));            //下文主循环 不涉及 i-1，故这里无需申请+1的空间
        for( int len = 1; len <= nold; ++len )
        {
            for( int b = 1; b + len - 1 <= nold ; ++b )
            {
                int e = b + len - 1;
                for( int m = b; m <= e; ++m )
                {
                    dp[b][e] = max(dp[b][e],
                        nums[b-1] * nums[m] * nums[e+1] 
                        + dp[b][m-1] + dp[m+1][e] );  //最后一个扎破 mid，其与beg、end相邻
                }
            }
        }

        return dp[1][nold];
    }
};
// @lc code=e
/* fish
题解：
https://leetcode-cn.com/problems/burst-balloons/solution/dong-tai-gui-hua-by-ivan_allen-2/

dp[i][j] 表示戳破 [i+1...j-1] 号气球的最大收益。

假设 k 号气球（i+1 <= k <= j-1）是 [i+1...j-1] 中最后一个被戳破的，则

dp[i][j] = max {for k = range(i+1, j -1) nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]}

作者：ivan_allen
链接：https://leetcode-cn.com/problems/burst-balloons/solution/dong-tai-gui-hua-by-ivan_allen-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */


/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (57.55%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    7.9K
 * Total Submissions: 13.7K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的
 * left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 说明:
 * 
 * 
 * 你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * 示例:
 * 
 * 输入: [3,1,5,8]
 * 输出: 167 
 * 解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 * 
 */
