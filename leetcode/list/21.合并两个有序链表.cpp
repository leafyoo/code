// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( !l1 || !l2) return (l1 ? l1 : l2);

        ListNode prehead(0);
        ListNode * p = & prehead;
        for( ; l1 && l2; p = p->next)
        {
            if ( l1->val < l2->val )
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
        }
        if ( l1 || l2 )
        {
            p->next = (l1 ? l1 : l2);
        }
        return prehead.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (59.64%)
 * Likes:    854
 * Dislikes: 0
 * Total Accepted:    182.6K
 * Total Submissions: 306K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */


