// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        stack<int> st;

        for( int i = min(9, n); i >= 1 ; --i)           //注意：降序压栈，才能保证 1 是在栈顶
            st.push(i);
        
        int idx = 0;
        while( !st.empty() )                    //对这棵10叉字典树，进行前序遍历
        {
            int cur = st.top();
            st.pop();
            res[ idx++ ] = cur;

            cur *= 10;                          //根节点值*10就是下一层 子节点的起始值。
            for( int i = 9; i >=0; --i)
            {
                if(cur + i <= n)
                    st.push(cur + i);
            }
        }

        return res;
    }
};
// @lc code=end

/* 
fish：前序遍历的思想。十叉树。
https://leetcode-cn.com/problems/lexicographical-numbers/solution/san-chong-fang-fa-by-jason-2/

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
 * 给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
 * 
 * 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
 * 
 */

