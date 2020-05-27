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

//找到的解法全是递归的，没有找到非递归的
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left = deep(root->left);
        int right = deep(root->right);

        if( abs(left - right) > 1 ) 
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }

    int deep(TreeNode* root)
    {
        if(!root) return 0;

        int left = deep(root->left);
        int right = deep(root->right);

        return 1 + max(left, right);
    }
};

// @lc code=end

/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (50.14%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    55.6K
 * Total Submissions: 110K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 * 
 * 
 */


/* 
未通过，
因为每个子树的深度是这个子树的最大深度，并不是最潜的那个叶子节点的高度。

错误case：
Testcase
[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
Answer
false

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode *> q;
        q.push(root);

        int minDeep = INT_MAX, currDeep = 1;
        while( !q.empty() )
        {
            int cnt = q.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                if(!p->left || !p->right)
                {
                    minDeep = min( minDeep, currDeep);
                    if(currDeep - minDeep > 1)
                        return false;
                }
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }

            ++currDeep;
        }

        return true;
    }
};

 */