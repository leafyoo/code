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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        
        for( ListNode * h = head; h; h = h->next )
            ++len;
        
        if(!head || k < 2 || k > len ) 
            return head;          //空指针判断

        ListNode prehead(0);
        ListNode *p =&prehead;
        p->next = head;    
        for( int i = 0; i < len/k; ++i)
        {
            for( int j = 0; j < k - 1; ++j)
            {
                ListNode *t = head->next;

                head->next = t->next;
                t->next = p->next;  //这里是p->next，因为第一次虽然可以是head，但是之后每次赋值就不是head了，只有p->next可以
                p->next = t;
            }
            p = head;
            head = head->next;
        }
        
        return  prehead.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (56.17%)
 * Likes:    378
 * Dislikes: 0
 * Total Accepted:    37.6K
 * Total Submissions: 66.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 */


