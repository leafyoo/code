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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        return create(preorder, inorder, 0, preorder.size()-1,   0, inorder.size()-1 );
    }

    TreeNode *create(vector<int>& pr, vector<int>& in, int pbeg, int pend, int ibeg, int iend )
    {
        if(pbeg > pend || ibeg > iend) return nullptr;

        TreeNode *root = new TreeNode( pr[ pbeg] );
        
        int iNextRoot = ibeg;
        for( ; iNextRoot <= iend; ++iNextRoot)
        {
            if( pr[pbeg] == in[ iNextRoot ] )
                break;
        }
        int leftNodeNum = iNextRoot - ibeg ;        //因为要除去iNextRoot之外，所以不用+1
        int rightNodeNum = iend - iNextRoot;

        //用三个点来demo就好了，前序是：根 左 右，那就是三部分，根只占一个节点
        //第一个元素是root，所以pbeg+1
        root->left = create(pr, in,  pbeg+1,                    pbeg + leftNodeNum,     ibeg,        iNextRoot-1);
        root->right = create(pr, in, (pend - rightNodeNum) +1,  pend,                   iNextRoot+1, iend);         

        return root;
    }
};
// @lc code=end
/* 

依次使用前序数组中的元素分割中序数组，分割后递归处理
preorder中的pos位置的元素preorder[pos]为根的子树必然对应着inorder数组中[left,right]之间的值。
一开始pos = 0，以preorder[0]为根的树，对应着inorder数组中[0, inorder.size()-1]之间的元素
preorder[0]在inorder中的位置为p，则将inorder数组分为[0, p-1]和[p+1, inorder.size()-1]两部分
这两部分分别对应左子树的节点集合和右子树的节点集合。

作者：yuexiwen
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/c-fen-zhi-by-yuexiwen/
 */

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.09%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    47.8K
 * Total Submissions: 74.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

