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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) 
            return head;

        ListNode prehead(0);
        ListNode * p = &prehead, *q = head, *end = nullptr;
        p->next = head;

        for( ; prehead.next != end;  )
        {
            p = &prehead;

            q = prehead.next; //不可以是 q = head; 因为交换节点之后，head也移到后面去了
            for( ; p && q && q->next && q->next != end; p = p->next )
            {
                if ( q->val > q->next->val )
                {
                    ListNode * t = q->next;

                    q->next = t->next;
                    t->next = p->next;
                    p->next = t;
                }
                else
                {
                    q = q->next;
                }
            }
            end = q; 
        }
        
        return prehead.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (63.80%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 63.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 * 
 */


//leaf:冒泡排序，时间复杂度是O（n2），提交时超长的测试用例失败。本题只可以用堆、归并、快排
/*
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode prehead(0);
        ListNode * p = &prehead, *q = head, *end = nullptr;
        p->next = head;

        for( ; prehead.next != end;  )
        {
            p = &prehead;
            
            q = prehead.next; //不可以是 q = head; 因为交换节点之后，head也移到后面去了
            for( ; p && q && q->next && q->next != end; p = p->next )
            {
                if ( q->val > q->next->val )
                {
                    ListNode * t = q->next;

                    q->next = t->next;
                    t->next = p->next;
                    p->next = t;
                }
                else
                {
                    q = q->next;
                }
            }
            end = q; 
        }
        return prehead.next;
    }
};
*/