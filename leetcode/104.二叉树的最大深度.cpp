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

//宽度优先搜索:适合大数据量的场景，不会导致栈溢出。
class Solution_BFS {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() )
        {
            int cnt = q.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            ++res;
        }
        return res;
    }
};


//深度优先搜索：栈可能溢出
class Solution_DFS {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max( maxDepth(root->left), maxDepth(root->right) ) + 1;
    }
};

// @lc code=end

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (72.14%)
 * Likes:    475
 * Dislikes: 0
 * Total Accepted:    134.5K
 * Total Submissions: 185.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
 * 
 */