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
    int globalMax ;
    int maxPathSum(TreeNode* root) 
    {
        if(!root) return 0;
        globalMax = INT_MIN;

        getMax( root );

        return globalMax;
    }

    int getMax(TreeNode* root) {
        if(!root) return 0;

        int lMax = getMax( root->left);
        int rMax = getMax( root->right);

        int belowRootMax = root->val + max(lMax, 0) + max(rMax, 0) ;            //如果这条路径不会穿越到root之上去。不可以递归，但是影响全局最大值
        int aboveRootMax = root->val + max(max(lMax, 0) , max(rMax, 0) );       //如果这条路径 会穿越到root之上去， root之下的只是一部分，那就可以递归

        globalMax = max(globalMax, max(belowRootMax, aboveRootMax ));

        return aboveRootMax;        //因为，只有会穿越到root之上去，才可以递归
    }    
};
// @lc code=end

/* 
fish:
解题思路：
二叉树 abc，a 是根结点（递归中的 root），bc 是左右子结点（代表其递归后的最优解）。
最大的路径，可能的路径情况：

    a
   / \
  b   c

1、b + a + c。
2、b + a + （a 的父结点）。
3、a + c + （a 的父结点）。

其中情况 1，表示如果不联络父结点的情况，或本身是根结点的情况。
这种情况是没法递归的，但是结果有可能是全局最大路径和。
情况 2 和 3，递归时计算 a+b 和 a+c，选择一个更优的方案返回，也就是上面说的递归后的最优解啦。

另外结点有可能是负值，最大和肯定就要想办法舍弃负值（max(0, x)）（max(0,x)）。
但是上面 3 种情况，无论哪种，a 作为联络点，都不能够舍弃。

作者：ikaruga
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

注意：max(rMax, 0)和这个一样的效果 (rMax > 0 ? rMax : 0)，用max更简洁明了
 */


/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.28%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 68.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

