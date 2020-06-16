
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
    bool same(TreeNode* p, TreeNode* q) {
        if(!p && !q) 
            return true;
        if(!p || !q) 
            return false;

        return (p->val == q->val) && 
            same(p->left, q->left) && same(p->right, q->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) 
            return true;
        if(!s) 
            return false;
        
         //函数开始到这里为止，都是判断当前树是否满足条件，下面的代码就是递归、丢给自己再处理了
         //所以这里是isSameTree，下面是isSubtree
        if( same(s, t) ) 
            return true;        //这里只能是same才行，看题目里的示例2

        return ( isSubtree(s->left, t) || isSubtree(s->right, t)) ;         //不一定要是same tree，是sub tree就可以了
    }
};
// @lc code=end
/* 
fish：注意，下面的示例2 里，是false！！！！

 */


/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 *
 * https://leetcode-cn.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (43.86%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 39.8K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s
 * 也可以看做它自身的一棵子树。
 * 
 * 示例 1:
 * 给定的树 s:
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 给定的树 t：
 * 
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
 * 
 * 示例 2:
 * 给定的树 s：
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * 
 * 给定的树 t：
 * 
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 返回 false。
 * 
 */
