// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        stack<int> stk;

        for( int i = min(9, n); i >= 1 ; --i)           //注意：降序压栈，才能保证 1 是在栈顶
            stk.push(i);
        
        int idx = 0;
        while( !stk.empty() )                    //对这棵10叉字典树，进行前序遍历
        {
            int cur = stk.top();
            stk.pop();
            res[ idx++ ] = cur;

            cur *= 10;                          //根节点值*10就是下一层 子节点的起始值。
            for( int i = 9; i >=0; --i)         //降序压栈，出栈才是升序
            {
                if(cur + i <= n)
                    stk.push(cur + i);
            }
        }

        return res;
    }
};
// @lc code=end

/* 
fish：前序遍历的思想。十叉树。
https://leetcode-cn.com/problems/lexicographical-numbers/solution/san-chong-fang-fa-by-jason-2/

图：
https://leetcode-cn.com/problems/lexicographical-numbers/solution/xian-xu-bian-li-10cha-shu-by-aknifejackzhmolong/

 */


/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode-cn.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (68.75%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 10.3K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n, 返回从 1 到 n 的字典顺序。
 * 
 * 例如，
 * 
 * 给定 n =13，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
 * 
 * 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
 * 
 */

