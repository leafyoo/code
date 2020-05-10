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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;

        ListNode prehead(0);
        prehead.next = head;
        ListNode *p = &prehead, *q = &prehead;          //fish：没必要所有场景下都要节省一个指针q而用head代替，因为这道题里，head后移之后并没有head的含义

        for( int i = 0; i < n; ++i)
        {
            q = q->next;
        }
        for( ; q->next;  )
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;            
        /* //删除链表节点，并不需要真实删除底层node，因为不一定是new出来的节点，也可能是在 全局的数据区。
        例如，这个链表中，某一个节点，我就是定义的全局的 ListNode 变量，把它单独链接到全链表中的，那就不能delete
        delete 会导致程序终止，非法的地址*/

        return prehead.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.51%)
 * Likes:    687
 * Dislikes: 0
 * Total Accepted:    121.9K
 * Total Submissions: 324.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */

