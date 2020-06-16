
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

//先中序遍历，然后判断是否是升序的
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) 
            return true;

        vector<int> res;
        traMidFirst( root, res );

        for( int i = 1; i < res.size(); ++i)
        {
            if(res[i] <= res[i-1])
                return false;
        }
        
        return true;
    }

    void traMidFirst(TreeNode * root, vector<int> &res )            
    {
        if(!root) 
            return;
        
        stack<TreeNode * > st;
        TreeNode * p = root;

        while( p || !st.empty() )           //中序遍历坑太多，上面不push，下面最后取top，这里条件也是两个 || 
        {
            while( p )
            {
                st.push( p );
                p = p->left;
            }

            res.push_back( st.top()->val );

            p = st.top() -> right;
            
            st.pop();
        }
    }
};


class Solution_recursion {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);                 //试想如果只有一个root节点，这里要 LONG_MIN, LONG_MAX 才能使得结果正确。
    }
    bool isBST(TreeNode * p, long  imin, long  imax)            //错误：这里应为 long
    {
        if(!p) 
            return true;                                     //错误：拼写错 为ture

        if(p->val <= imin || p->val >= imax)                    //step 1： 当前节点满足bst
            return false;

        return isBST(p->left, imin, p->val)                     //step 2： 左右两个节点也满足bst。
            && isBST(p->right, p->val, imax);                   // 这里该怎么填写？ 按照只有3个节点的tree想一下就知道了
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (28.90%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    75.9K
 * Total Submissions: 259.5K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
 * 
 * 
 */


/*
未通过： 
因为缺少树与树之间值的比较

class Solution {
public:
    bool isBST;
    bool isValidBST(TreeNode* root) {
        isBST = true;
        visit(root);
        return isBST;
    }
    void visit(TreeNode * p )        //错误：这里少了函数类型  void
    {
        if( !p || !isBST) 
            return;
        if((p->left && (p->left->val >= p->val) ) 
            || ( p->right && (p->val >= p->right->val)) 
            || p->left->val )
            isBST = false;
        else
        {
            visit(p->left);
            visit(p->right);
        }
    }
};
 */