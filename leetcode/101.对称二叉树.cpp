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
class Solution_recursion {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root ) 
            return true;

        return sym(root->left, root->right);
    }

    bool sym(TreeNode* l, TreeNode* r)
    {
        if(!l || !r)
        {
            if(!l && !r) 
                return true;
            else
                return false;
        }

        return (l->val == r->val) 
            && sym(l->left, r->right) 
            && sym(l->right, r->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root ) 
            return true;

        queue<TreeNode*> ql, qr;
        ql.push(root->left);
        qr.push(root->right);
        while( !ql.empty() && !qr.empty() )
        {
            TreeNode* l = ql.front() , *r = qr.front();
            ql.pop();
            qr.pop();

            if(!l && !r)                              //错误：这里写成了：if(!ql && !qr)
                continue;                               //结尾返回true，所以过程中只判false
            if((!l || !r) || (l->val != r->val))
                return false;

            ql.push(l->left);              //错误：这里不同于遍历，不可判空而只push非空的，会漏掉空节点的情况，导致整体逻辑边复杂
            ql.push(l->right);
            qr.push(r->right);
            qr.push(r->left);
        }
        
        return true;                
    }
};
/* 
fish
可以优化为一个queue
 */

/* 
fish:
时间复杂度：O(n)O(n)，因为我们遍历整个输入树一次，所以总的运行时间为 O(n)O(n)，其中 nn 是树中结点的总数。
空间复杂度：递归调用的次数受树的高度限制。在最糟糕情况下，树是线性的，其高度为 O(n)O(n)。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为 O(n)O(n)。

作者：LeetCode
链接：https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode/

 */


// @lc code=end


/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.02%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    103.1K
 * Total Submissions: 204.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */
