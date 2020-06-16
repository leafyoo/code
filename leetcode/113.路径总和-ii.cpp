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

        if(!root) 
            return res;

        queue<TreeNode*> qn;
        queue<int> qs;
        qn.push( root);
        qs.push( root->val);

        map<TreeNode*, TreeNode*> mp;
        mp[root] = nullptr;
        set<TreeNode*> st;

        while( !qn.empty() )
        {
            int cnt = qn.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode * p = qn.front();
                qn.pop();
                int s = qs.front();
                qs.pop();

                //错误1：不可以( s > sum ) continue;，节点值可能为负；错误2：漏掉了 !p->left && !p->right
                if(!p->left && !p->right && s == sum)    
                    st.insert( p );         //把合适的叶子节点地址存入set
                else
                {
                    if(p->left)
                    {
                        qn.push(p->left);   
                        qs.push( p->left->val + s);
                        mp[ p->left ] = p;
                    }
                    if(p->right)
                    {
                        qn.push(p->right);   
                        qs.push( p->right->val + s);
                        mp[ p->right ] = p;
                    }
                }
            }
        }

        //这里存满了叶子节点的地址，取出每一个叶子节点地址，然后顺腾摸瓜一路到root
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
