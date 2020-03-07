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


/* 
fish:
左右根 ： 根右左 的取反。 然后最终再reverse一下。
因为后续遍历中，根是最后出现，这导致利用栈的思想的话，很难区分节点是否已经遍历过，容易死循环。
而reverse并没有让性能差太多。因为用其他的变量记录等方式，本身就会让后续遍历时间复杂度变大。
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > st;

        TreeNode* p = root;
        while( p || !st.empty() )
        {
            while( p )
            {
                res.push_back( p->val );
                st.push( p);
                p = p->right;                       //注意：根右左，这里是right
            }
            p = st.top()->left;
            st.pop();
        }

        reverse(res.begin(), res.end());            //注意：不可少

        return res;
    }

};


class Solution_recursion {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        tra(root, res);
        return res;
    }

    void tra(TreeNode* p, vector<int> &res)
    {
        if(!p) return ;
        tra( p->left, res);
        tra( p->right, res);
        res.push_back( p->val);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.11%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    55.4K
 * Total Submissions: 78.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
