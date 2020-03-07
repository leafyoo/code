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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while( p || !st.empty() )
        {
            while( p )
            {
                res.push_back( p->val );
                st.push( p );
                p = p->left;
            }

            p = st.top()->right;
            st.pop();
        }
        
        return res;
    }
};

class Solution_recursion {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        tra(root, res);
        return res;
    }
    void tra(TreeNode* t, vector<int> & res)
    {
        if( !t) return;
        res.push_back( t->val);
        tra( t->left, res);             //错误：语法错误：这里少了一个参数 , res
        tra( t->right, res);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (64.08%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 115.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
