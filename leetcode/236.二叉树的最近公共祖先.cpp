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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(!p || !q) return ( !p ? q : p);
        
        return visit(root, p, q) ;

    }

    TreeNode* visit(TreeNode* r, TreeNode* p, TreeNode* q) 
    {
        if(!r ||  r == p || r == q )            //dfs的返回点
            return r;

        TreeNode* left = visit( r->left, p, q);                 //既然是递归，这里看成已求出结果为left
        TreeNode* right = visit( r->right, p, q);

        if(left && right)                   //两个子树中搜索结果均非空，说明left和right一个是p一个是q                         
            return r;
        if( !left || !right)                //两边一个子树为空，返回另一个。
            return ( !left ? right : left );

        return nullptr;                     //递归，一定要返回。
    }
};
/* 
我们使用DFS搜索每一个节点的左右子树：
1、若子树上存在p和q的公共节点，返回此公共节点
2、若不存在公共节点，但是存在p或q任意一个节点，返回此节点
3、若不存在公共、p、q节点，则返回null。

那么，有以下几个结论：
0、递归的返回点：若当前节点为null、p、q之一，直接返回当前节点
1、然后递归左右子树，因为是递归，使用函数后可认为左右子树【已经算出结果】，用 left和right分别代表在左右子树找到的公共节点
2、若左子树返回null，则函数返回值为右子树返回值
3、若左子树、右子树返回值均为非null，则肯定为一个p，一个q，则公共节点为当前root节点
4、最后一种情况，即左子树返回非null，右子树返回null，则函数返回值为左子树返回值

*针对p是q的子节点这种特殊情况，上述方案依然可行（但就没有办法剪枝了，可以考虑针对此情况加一个标记，不再遍历右子树）。

作者：lava-4
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/java-dfs-jian-zhi-9ms9244-by-lava-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
时间复杂度是O(n)O(n)：每个结点最多遍历一次或用主定理，空间复杂度是O(n)O(n)：需要系统栈空间
 
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/c-jing-dian-di-gui-si-lu-fei-chang-hao-li-jie-shi-/

*/

//层序遍历，用map记录每个节点的父节点，最后从根往root遍历记录写入set，找公共节点
class Solution_queue {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(!p || !q) return ( !p ? q : p);
        
        queue<TreeNode*> que;
        map<TreeNode*, TreeNode*> mp;
        que.push(root);
        mp[ root ] = nullptr;
        while( mp.find( q ) == mp.end() || mp.find( p ) == mp.end() )       //错误：这里错写为  != mp.end()
        {
            TreeNode* p = que.front();
            que.pop();
            if(p->left)
            {
                que.push( p->left);
                mp[ p->left ] = p;
            }
            if(p->right)
            {
                que.push( p->right);
                mp[ p->right ] = p;
            }
        }

        set<TreeNode*> se;
        for(TreeNode* t = p;  t; t = mp[t])
            se.insert(t);
        for(TreeNode* t = q;  t; t = mp[t])
        {
            if( se.end() != se.find(t) )
                return t;
        }
        return nullptr;
    }

};
// @lc code=end

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (59.74%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    48.9K
 * Total Submissions: 81.2K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 * 
 * 
 */