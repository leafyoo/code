
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int deep = 1;
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() )
        {
            int cnt = q.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                if(!p->left && !p->right)
                    return deep;
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            ++deep;
        }

        return deep;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.48%)
 * Likes:    222
 * Dislikes: 0
 * Total Accepted:    56.6K
 * Total Submissions: 135.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
 */
