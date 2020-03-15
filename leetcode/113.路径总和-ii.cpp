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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;

        if(!root) return res;

        queue<TreeNode*> qnode;
        queue<int> qsum;
        qnode.push( root);
        qsum.push( root->val);

        map<TreeNode*, TreeNode*> mp;
        mp[root] = nullptr;
        set<TreeNode*> st;

        while( !qnode.empty() )
        {
            int cnt = qnode.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode * p = qnode.front();
                qnode.pop();
                int isum = qsum.front();
                qsum.pop();

                if(!p->left && !p->right && isum == sum)    //错误1：不可以( isum > sum ) continue;，节点值可能为负；错误2：漏掉了 !p->left && !p->right
                    st.insert( p );
                else
                {
                    if(p->left)
                    {
                        qnode.push(p->left);   
                        qsum.push( p->left->val + isum);
                        mp[ p->left ] = p;
                    }
                    if(p->right)
                    {
                        qnode.push(p->right);   
                        qsum.push( p->right->val + isum);
                        mp[ p->right ] = p;
                    }
                }
            }
        }

        for( set<TreeNode*>::iterator it = st.begin(); it != st.end(); ++it)
        {
            vector<int> v;
            for( TreeNode* p = *it; p ; p = mp[p] )
                v.push_back( p->val );
            reverse(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }

};
// @lc code=end




/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (58.62%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    34K
 * Total Submissions: 57.6K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
