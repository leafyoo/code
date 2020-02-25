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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode prehead(0);
        prehead.next = head;

        ListNode *p = &prehead;

        for( ; p && p->next;  )
        {
            if ( p->next->val == val )
                p->next = p->next->next;
            else
                p = p->next;
        }
        return prehead.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.01%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    58.9K
 * Total Submissions: 133.8K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */

