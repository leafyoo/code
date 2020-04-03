// @lc code=start
class Solution {
public:
    int getStep(int n, long long beg, long long end)            //错误：溢出了，所以这里要long long
    {
        long long step = 0;
        while( beg <= n )
        {
            step += min(end-1, (long long)n) - beg + 1;
            beg *= 10;
            end *= 10;
        }
        
        return step;
    }

    int findKthNumber(int n, int k) {
        int res = 0;
        int cur = 1;
        k = k-1;
        while( k > 0 )
        {
            int step = getStep(n, cur, cur+1);      //获取前序遍历时，从cur到 cur+1需要走过的节点数量
            if(k >= step)
            {
                k = k - step;
                cur = cur + 1;      //移到右边的节点
            }
            else
            {
                k = k-1;            //只多遍历了一个数，-1
                cur = cur * 10;     //移到下一层的节点
            }
        }
        return cur;
    }
};
// @lc code=end

/* fish：
求字典序第k个就是十叉树【前序遍历】访问的第k节点（上文中的step）！

https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/shi-cha-shu-by-powcai/
 */

/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (32.62%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 10K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
 * 
 * 注意：1 ≤ k ≤ n ≤ 10^9。
 * 
 * 示例 :
 * 
 * 
 * 输入:
 * n: 13   k: 2
 * 
 * 输出:
 * 10
 * 
 * 解释:
 * 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 * 
 * 
 */

