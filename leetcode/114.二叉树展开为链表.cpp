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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* p = root;
        while( p )
        {
            if( p->left )
            {
                TreeNode* leftR = p->left;
                while( leftR->right )
                    leftR = leftR->right;
                
                leftR->right = p->right;
                p->right = p->left;
                p->left = nullptr;              //left要置null，不然不能通过
            }
            p = p->right;
        }
    }
};
/* 
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/

fish:
思路：将左子树当做一个节点，插入在右子树里。

 */


class Solution_recursion {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* p = root;
        if( p->left )
        {
            TreeNode* leftR = p->left;
            while( leftR->right )
                leftR = leftR->right;
            
            leftR->right = p->right;
            p->right = p->left;
            p->left = nullptr;              //left要置null，不然不能通过
        }
    }
};

// @lc code=end

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (67.45%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    29.8K
 * Total Submissions: 43.9K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */

