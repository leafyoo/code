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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty()) 
            return nullptr;

        return create(postorder, inorder, 0, postorder.size()-1,   0, inorder.size()-1 );
    }

    //后续遍历：左右根，所以从后往前推才能让第一个是根，然后下一部分是右，然后是左，
    TreeNode *create(vector<int>& po, vector<int>& in, int pb, int pe, int ib, int ie )
    {
        if(pb > pe || ib > ie) 
            return nullptr;

        TreeNode *root = new TreeNode( po[ pe] );         //注意这里 是pend
        
        //遍历中序，找出元素在中序里的索引iNextRoot
        int iRoot = ib;
        for( ; iRoot <= ie; ++iRoot)
        {
            if( po[pe] == in[ iRoot ] )
                break;
        }
        int lCnt = iRoot - ib ;        //因为要除去iNextRoot之外，所以不用+1
        int rCnt = ie - iRoot;

        //用三个点来demo就好了
        //从后往前post里第一个元素是root，所以下面pend - 1
        root->right = create(po, in, (pe - rCnt) ,  pe - 1, iRoot+1, ie);         
        root->left = create(po, in,  pb, pb + lCnt - 1, ib, iRoot-1);

        return root;
    }
};
// @lc code=end
/* fish：
可以将值和中序遍历的索引存入map，
然后就不用每次都for( ; iRoot <= ie; ++iRoot) 
 */


/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.48%)
 * Likes:    187
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 46.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */

