
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

//栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;                      //错误：这里写成了 stack<int> 

        TreeNode* p = root;
        while(p || !st.empty())
        {
            //“左”
            while( p )       //错误：这里写成判断 p->left 导致死循环。 注意：一直要贪婪，走到叶子节点才行，那当然 while( p )   
            {
                st.push( p);
                p = p->left;   
            }

            //“根”
            res.push_back( st.top()->val );     // 录入“根”，之后，左和根相当于遍历完了，可以pop掉了，先切入右分支
           
           //“右”
            p = st.top()->right;                //不一定要在循环开头赋值
            
            st.pop();
        }

        return res;
    }

};

/* 
//递归解法
时间复杂度：O(n) 。递归函数 T(n) = 2 \cdot T(n/2)+1T(n)=2⋅T(n/2)+1。
空间复杂度：最坏情况下需要空间O(n) ，平均情况为 O(logn)。
 */
class Solution_recursion {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;

        tra(root, res);

        return res;
    }

    void tra(TreeNode* p, vector<int> &res)
    {
        if(!p)
            return;

        tra( p->left, res );
        
        if(p)
            res.push_back(p->val);
        
        tra( p->right, res );
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.15%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    114.4K
 * Total Submissions: 162.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */


/*
未通过：这个陷入了死循环，
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3

会一直在2 - 3之间循环，因为2已经遍历过了但是没有标记


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        stack<TreeNode*> st;                      //错误：这里写成了 stack<int> 
        st.push( root );
        while( !st.empty() )
        {
            TreeNode * t = st.top();
            if(t->left)
                st.push(t->left);
            else
            {
                res.push_back( t->val );
                std::cout << t->val << ":" 
                    << t->right << ":" 
                    << t->left << ":" << t << std::endl;
                st.pop();
                if( t->right )
                    st.push( t->right);
            }
            std::cout << t->val << ":" 
                    << t->right << ":" 
                    << t->left << ":" << t <<  <<st.size() << " message  " << std::endl;
        }

        return res;
    }

};

改造为这样就可以了：
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        stack<TreeNode*> st;                      //错误：这里写成了 stack<int> 
        st.push( root );
        bool leftVistFlag = false;
        while( !st.empty() )
        {
            TreeNode * t = st.top();
            if(t->left && !leftVistFlag)
            {
                st.push(t->left);
                leftVistFlag = false;
            }
            else
            {
                res.push_back( t->val );
                st.pop();
                if( t->right )
                {
                    st.push( t->right);
                    leftVistFlag = false;
                }
                else
                {
                    leftVistFlag = true;
                }
            }
        }

        return res;
    }

};


*/