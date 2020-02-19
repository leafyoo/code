
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//结果可以不用reverse
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return (l1 ? l1 : l2);

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode prehead(0);
        ListNode * p = &prehead;
        
        int up = 0;
        for( ; l1 || l2;  )
        {
            p->next = new ListNode(0);
            p = p->next;

            int x = (l1 ? l1->val : 0);
            int y = (l2 ? l2->val : 0);
            
            p->val = (x + y + up) % 10;
            up = (x + y + up) / 10;

            l1 = (l1 ? l1->next : l1);        
            l2 = (l2 ? l2->next : l2);        
        }

        if ( up )
        {
            p->next = new ListNode(0);
            p = p->next;
            p->val = up;
        }

        return reverse(prehead.next);
    }

    ListNode* reverse(ListNode* h) 
    {
        ListNode* p = nullptr;
        while( h )   //这里的条件，最后再加
        {
            ListNode* t = h->next;

            h->next = p;
            p = h;     //p , h,这几个指针在每一轮的循环里都要移动，当然要在内部发生赋值。
            h = t;
        }
        return p;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (53.89%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 24.6K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
 * 
 * 
 */
