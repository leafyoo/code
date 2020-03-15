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
    int maxLen;

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        maxLen = 0;
        getDeep(root);
        return maxLen - 1;                          //下文统计的是节点的数目，这里是边长，边长在节点数目基础上减一
    }

    int getDeep(TreeNode* p)
    {
        if(!p)
            return 0;
        int l = getDeep(p->left );
        int r = getDeep(p->right );
        maxLen = max(maxLen, l + r +1);     

        return max(l, r) + 1;                       //求深度的过程中，顺便更新maxLen，所以返回这里还是要注意返回深度。
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.03%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 45.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
 * 
 * 示例 :
 * 给定二叉树
 * 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 
 */