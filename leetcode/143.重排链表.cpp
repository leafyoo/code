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
    void reorderList(ListNode* head) {
        int len = 0;
        for(ListNode *p = head; p; p = p->next) ++len;
        if(len < 3)return;

        ListNode * mid = head;
        for( int i = 0; i < len/2; ++i)
            mid = mid->next;

        ListNode *q = mid->next;
        while( q->next )            //翻转后一半链表
        {
            ListNode *t = q->next;

            q->next = t->next;
            t->next = mid->next;
            mid->next = t;          //依然挂在mid后面
        }

        while( mid && mid ->next )  //把后半段逐个往前迁移
        {
            ListNode *t = mid->next;

            mid->next = t->next;
            t->next = head->next;
            head->next = t;

            head = head->next->next;
        }

        return;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (54.48%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 29.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */
