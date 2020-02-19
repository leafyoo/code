// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//fishyoo:链表反转，这么简单就不要定义哑结点了
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        for( ; head;)   //这里的条件，最后再加
        {
            ListNode* tmp = head->next;

            head->next = pre;   //注意：定义哑节点与否在这里不同，因为 pre指针没有next成员，所以不能指向别处
            pre = head;     //pre , head,这几个指针在每一轮的循环里都要移动，当然要在内部发生赋值。
            head = tmp;
        }
        return pre;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (67.03%)
 * Likes:    767
 * Dislikes: 0
 * Total Accepted:    157.6K
 * Total Submissions: 235.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */
