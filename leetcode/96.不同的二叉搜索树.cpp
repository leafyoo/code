// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);     //dp[i]，i个节点时，不同的二叉搜索树 的数量
        dp[0] = 1;
        dp[1] = 1;

        for( int i = 2; i <= n; ++i)                    //这棵树所有所有的节点数
        {
            for( int root = 1; root <= i; ++root)       //根节点在第 root 个节点处 切分为左右两个子树
            {
                dp[i] += dp[root - 1] * dp[i-root];     // [1, 2, 3, ... root ... i ]，所以两部分分别是：（root - 1）个， （i-root）个
            }
        }

        return dp[n];
    }
};
// @lc code=end

/* 
fish：
对于每一个根i他都是由左边子树（1, 2, ..., i - 1)和右边子树（i + 1, i + 2, ..., n)组成的。
因此他的个数肯定是两个子树情况的积。而且，这种根一共有n个，再将这些加起来就可以了。

链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/xi-xiang-yi-xia-huan-shi-hen-jian-dan-de-by-jerry-/

 */

/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (64.73%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    32.9K
 * Total Submissions: 50.6K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */
