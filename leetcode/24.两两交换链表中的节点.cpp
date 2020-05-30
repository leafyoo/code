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
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(0);
        ListNode *p = &prehead, *q = head, *t = nullptr;
        p->next = head;

        for( ; q && q->next;  )
        {
            t = q->next;                        //这里用了哑结点，赋值情况和链表反转的不一样
            q->next = t->next;
            t->next = p->next;
            p->next = t;

            //上面都只是更新了next指针，这里要更新p的值
            p = p->next->next;
            q = q->next;
        }

        return prehead.next;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.27%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    71.4K
 * Total Submissions: 111.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */
