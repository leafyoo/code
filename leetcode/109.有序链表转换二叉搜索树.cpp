// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return create(head, nullptr);
    }

    TreeNode* create(ListNode* b, ListNode* e) 
    {
        if(b == e) 
            return nullptr;                            //错误：这里要是null，无子节点了的

        ListNode * s = b, * f = b;

        //因为这里是通过  != e 来判断结束条件的，所以不需要将链表切断！
        while( f != e && f->next != e )                 //错误，写成了 while( f && f->next )
        {
            s = s->next;
            f = f->next->next;
        }

        TreeNode* root = new TreeNode( s->val );
        root->left = create(b, s) ;
        root->right = create(s->next, e) ;

        return root;
    }

};
// @lc code=e

/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (70.28%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 26.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

