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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) 
            return vector<vector<int> > ();       //技巧：创建临时的空的vector

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
            res.push_back(v);
        }

        return res;                               
    }

};


class Solution_recrusion {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int> > ();       //技巧：创建临时的空的vector

        int deep = getDeep(root);
        vector<vector<int> > res( deep );
        visit(root, 0, res);

        return res;                                     //错误：这里漏掉了 return res; 
    }

    void visit(TreeNode* p, int n, vector<vector<int> > & res)
    {
        if(!p) return;

        res[n].push_back( p->val );
        visit(p->left, n+1, res);                       //注意：这里是n+1
        visit(p->right, n+1, res);
    }

    int getDeep(TreeNode* root)
    {
        if(!root) return 0;

        return max(getDeep(root->left ), getDeep(root->right ) ) + 1;
    }

};
// @lc code=end

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (60.83%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    86.1K
 * Total Submissions: 141K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

