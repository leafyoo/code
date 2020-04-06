
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);
        
        bool rev = false;            //逆向，从右到左
        while( !q.empty() )
        {
            int cnt = q.size();

            vector<int> v;
            for( int i = 0; i < cnt; ++i)   //取完当前层的节点
            {
                TreeNode* p = q.front();
                q.pop();
                v.push_back(p->val);        //取当前层的值

                if(p->left) 
                    q.push(p->left);        //预存下一层节点
                if(p->right) 
                    q.push(p->right);
            }

            if(rev)
                reverse(v.begin(), v.end());
            rev = !rev;
            
            res.push_back( v );
        }

        return res;
    }
};
/* 
fish：
思路：同层序遍历，用queue，只是vector隔行反转。
 */

class Solution_2stack {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> res;
        stack<TreeNode*> st;
        st.push(root);
        bool reverse = true;            //逆向，从右到左
        while( !st.empty() )
        {
            int cnt = st.size();
            vector<int> v;
            stack<TreeNode*> stLower;
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = st.top();
                st.pop();
                v.push_back(p->val);

                if(reverse)
                {
                    if(p->left) stLower.push(p->left);
                    if(p->right) stLower.push(p->right);
                }
                else
                {
                    if(p->right) stLower.push(p->right);
                    if(p->left) stLower.push(p->left);
                }
            }
            reverse = !reverse;
            st = stLower;
            res.push_back( v );
        }

        return res;
    }
};
/* 
fish：
思路：用两个stack。
 */

// @lc code=end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (53.61%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 66K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */