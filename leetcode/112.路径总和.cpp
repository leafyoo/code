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

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;

        queue<TreeNode* > qnode;
        queue<int > qway;

        qnode.push(root);
        qway.push(root->val);
        
        while( !qnode.empty() )
        {
            int cnt = qnode.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = qnode.front();
                qnode.pop();
                int way = qway.front();
                qway.pop();

                if(!p->left && !p->right && way == sum)
                    return true;

                if(p->left)
                {
                    qnode.push(p->left);
                    qway.push(way + p->left->val);                  //注意：这里和下面 qway.push 要执行两次，qnode和qway的size永远是一比一
                }
                if(p->right)
                {
                    qnode.push(p->right);
                    qway.push(way + p->right->val);
                }
            }
        }

        return false;                   //通用注意：全局目的是找有，则在中间找到有则return，在结尾返回无。
    }

};

class Solution_DFS {
public:
    int sumMember;                                  //对象成员，记得根据函数参数来初始化

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;

        sumMember = sum;
        return path(root, 0);
    }

    int path(TreeNode* p, int total )
    {
        if(!p) return false;
        
        total += p->val;

        if( !p->right && !p->left )                 //错误： 这才是叶子节点的必要条件,根据!p并不能判断是叶子节点
        {
            if(sumMember == total)   
                return true;
            return false;
        }

        return ( path(p->left ,  total ) 
            || path(p->right,  total ) );           //谁满足都行
    }

};
/* 
错误：
错误case:
[1,2]
1

下面判断if( !p )而返回，并不对，因为叶子节点并不是!p 
而是
    int path(TreeNode* p, int total )
    {
        if( !p )
        {
            if(sumMember == total)   
                return true;
            return false;
        }

        return ( path(p->left ,  total + p->val) 
            || path(p->right,  total + p->val ) );
    }

 */


// @lc code=end

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (48.95%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    56.3K
 * Total Submissions: 114.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
 * 
 */