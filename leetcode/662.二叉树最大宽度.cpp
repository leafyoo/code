// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 1;
        
        queue< pair<TreeNode *, unsigned long long> > q;        //错误：这里是int 或者 long long 都会溢出
        q.push( {root, 1} );
        
        while( !q.empty() )
        {
            int cnt = q.size();
            res = max(res, (int)(q.back().second - q.front().second) + 1);     //错误：这里要+1
            
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();

                if(p->left)
                    q.push(make_pair(p->left, 2 * idx));
                if(p->right)
                    q.push(make_pair(p->right, 2 * idx + 1));
            }
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 *
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (35.82%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 16.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary
 * tree）结构相同，但一些节点为空。
 * 
 * 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * 
 * ⁠          1
 * ⁠        /   \
 * ⁠       3     2
 * ⁠      / \     \  
 * ⁠     5   3     9 
 * 
 * 输出: 4
 * 解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        /  
 * ⁠       3    
 * ⁠      / \       
 * ⁠     5   3     
 * 
 * 输出: 2
 * 解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2 
 * ⁠      /        
 * ⁠     5      
 * 
 * 输出: 2
 * 解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /     \  
 * ⁠     5       9 
 * ⁠    /         \
 * ⁠   6           7
 * 输出: 8
 * 解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
 * 
 * 
 * 注意: 答案在32位有符号整数的表示范围内。
 * 
 */

