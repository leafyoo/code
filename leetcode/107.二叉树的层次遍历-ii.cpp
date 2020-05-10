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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int> > ();       //技巧：创建临时的空的vector

        vector<vector<int> > res;

        queue<TreeNode*> q;                              //错误：这里写成了queue<int>
        q.push(root);
        while( !q.empty())
        {
            int cnt = q.size();                         //记录一层的节点数量
            vector<int> v;                              //局部变量就放局部，可读性、维护性更重要，不要考虑所谓的性能
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front();
                v.push_back( p->val );
                q.pop();

                if(p->left)
                    q.push( p->left);
                if(p->right)
                    q.push( p->right);
            }    
            
            res.insert(res.begin(), v);     //整体和 102题一致，就这里不一样
        }

        return res;                               
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (64.65%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    51.7K
 * Total Submissions: 79.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

