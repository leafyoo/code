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
    vector<TreeNode*> generateTrees(int n) {
        if(n < 1) 
            return vector<TreeNode*> ();

        return dfs(1, n);
    }

    vector<TreeNode *> dfs(int beg, int end)
    {
        vector<TreeNode *> res;
        if(beg > end)
        {
            res.push_back(nullptr);         //错误，这里直接return 空的vector不行。此处必须给vector里插入一个元素： nullptr。这样才能在下面的循环中给 左右子节点赋值nullptr
            return res;
        }
        
        for( int root = beg; root <= end; ++root)       //【1】以区间[beg, end]之间的每一个节点为root，以lRootVec左子树集合、rRootVec右子树集合枚举所有组合方案
        {
            vector<TreeNode *> lRootVec = dfs(beg, root-1);     //【2】以区间[beg, root-1]内的所有节点构造BST，可以构造出来的所有的树的root节点的集合
            vector<TreeNode *> rRootVec = dfs(root+1, end);

            //【3】分别从lRootVec、rRootVec两个集合中拎出来一个分别挂在root的左右两边，一共有(lRootVec.size()  *  rRootVec.size())种组合
            for( vector<TreeNode *>::iterator lit = lRootVec.begin(); lit != lRootVec.end(); ++lit)
            {
                for( vector<TreeNode *>::iterator rit = rRootVec.begin(); rit != rRootVec.end(); ++rit)
                {
                    TreeNode * p = new TreeNode( root );
                    p->left = *lit;
                    p->right = *rit;
                    res.push_back( p );              //【4】如【2】处所说，要把这棵树的root节点塞入总的root节点集合内。
                }                
            }
        }

        return res;
    }

};
// @lc code=end

/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (61.36%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 35.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
