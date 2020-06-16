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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) 
            return vector<string>();
        vector<string> res;

        queue<TreeNode *> qn;           //n : node
        queue<string> qp;               //p : path
        
        qn.push(root);
        qp.push( to_string(root->val) );

        while( !qn.empty() )
        {
            int cnt = qn.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode *p = qn.front();
                qn.pop();
                string path = qp.front();
                qp.pop();

                if(!p->left && !p->right)
                    res.push_back( path );

                if( p->left)
                {
                    qn.push( p->left );
                    qp.push( path + "->" + to_string( p->left->val) );
                }
                if( p->right)
                {
                    qn.push( p->right );
                    qp.push( path + "->" + to_string( p->right->val) );
                }
            }
        }

        return res;
    }
};

class Solution_DFS {
public:
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) 
            return vector<string>();

        handler(root , string());                   //传递空string ：  string()

        return res;
    }

    void handler(TreeNode* p , string path)
    {
        if(!p)
            return ;

        path += (path.empty() ? "" : "->" ) + to_string( p->val );

        if(!p->left && !p->right)
        {
            res.push_back( path );
            return;
        }

        handler( p->left ,  path) ;
        handler( p->right , path) ;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (62.03%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 43.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */
