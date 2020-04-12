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
    vector<int> numsMember;                             //【leetcode官方题解的做法】递归中，采用对象成员，减少参数传递
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        numsMember = nums;
        
        return handler(0, nums.size() - 1 );
    }

    TreeNode* handler(int left, int right )                 //错误：这种数组大范围的处理，要按照区间来压缩问题规模，然后才能递归。一开始是只处理一个val，导致很难递归。
    {
        if(left > right)
            return nullptr;

        int mid = (left + right)/2;

        TreeNode *p = new TreeNode( numsMember[mid]);
        p->left = handler( left, mid-1 );
        p->right = handler( mid+1, right );

        return p;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (69.07%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    52.5K
 * Total Submissions: 75.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

