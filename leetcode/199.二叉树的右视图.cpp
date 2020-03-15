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
//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        while( !q.empty() )
        {
            res.push_back( q.back()->val );         // 错误： res.push_back( q.back() ) 少了 ->val

            int cnt = q.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                if(p->left)
                    q.push( p->left );
                if(p->right)
                    q.push( p->right );
            }
        }

        return res;
    }
};

class Solution_DFS {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        DFS(root, res, 0);
        return res;
    }

    void DFS(TreeNode* p, vector<int> &res, int level)
    {
        if(!p)
            return;
        if(res.size() == level)
            res.push_back( p->val );

        DFS(p->right, res, level+1);
        DFS(p->left, res, level+1);
    }
};

/*
错误：
错误case：
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 /     
 4 ⁠     
会导致先开始选择了3（右分支），而在后面错过了左分支4

    void DFS(TreeNode* p, vector<int> &res)
    {
        if(!p)
            return;
        res.push_back( p->val );

        if(p->right)
            DFS(p->right, res);
        else if(p->left)
            DFS(p->left, res);
    }

*/

// @lc code=end

/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (63.25%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    19.6K
 * Total Submissions: 30.8K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
 */

