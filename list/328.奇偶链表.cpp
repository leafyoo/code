
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//fishyoo:因为奇数偶数两个链表是基于旧的链表生成，所以，旧的链表的节点next指针必须发生变化才行。
//说明：p1->next的含义是p1指向的对象（节点）的next成员； p1 的含义是 一个节点类型的指针，这个四字节的变量里存着一个地址（节点的地址）
//题解，看leetcode 官方题解：https://leetcode-cn.com/problems/odd-even-linked-list/solution/qi-ou-lian-biao-by-leetcode/
//总结:通过修改原有链表的节点指向，使得新生成2个链表，然后把偶数链表拼接在奇数之后
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;

        ListNode *p1 = head, *p2 = head->next, *head2 = head->next;

        while( p2 && p2->next ) 
        {
            p1->next = p1->next->next; //这些都是存放指针（node 节点的地址） p1, p1->next, p1->next->next 
            p1 = p1->next;

            p2->next = p2->next->next;
            p2 = p2->next;
        }

        p1->next = head2;

        return head;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 *
 * https://leetcode-cn.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (61.18%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 43K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2->1->3->5->6->4->7->NULL 
 * 输出: 2->3->6->7->1->5->4->NULL
 * 
 * 说明:
 * 
 * 
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
 * 
 * 
 */
