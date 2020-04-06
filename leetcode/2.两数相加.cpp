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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;          //把该有的分拿到，代码简约第一，规范第二
        if(!l2) return l1;
        ListNode head(0);           //next构造函数已经有默认值NULL了，这里不必 ListNode(0, NULL)  //如果这里new，那下文还有delete
        ListNode * p = &head;

        int up = 0, x = 0, y = 0;
        //错误： 这里要 ||,  因为up进位可能还会和后续的产生up，所以劲大限度在这里处理完up
        while( l1 || l2 )                
        {
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;

            p->next = new ListNode(0);
            p->next->val = (up + x + y)%10;         //错误：, 三值相加！，这里不是： up + (x + y)%10！
            up = (up + x + y)/10;
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            p = p->next;
        }
        if ( up )                                   //fish注意：不要遗漏最后的up
            p->next = new ListNode(up);
        return head.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.63%)
 * Likes:    3912
 * Dislikes: 0
 * Total Accepted:    325.4K
 * Total Submissions: 888.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */
