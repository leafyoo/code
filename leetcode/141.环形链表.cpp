
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
    bool hasCycle(ListNode *head) 
    {
        if(!head || !head->next) 
            return false;  //一个节点成环也被这里考虑到了，因为head->next == head 而不是null

        ListNode *s = head, *f = head;    //s: slow, f: fast
        while(  s && f && f->next )
        {
            s = s->next;
            f = f->next->next;

            if(s == f) 
                return true;
        }

        return false;   //上面循环结束了，这里必然是无环了。不必再判断了
    }
};
// @lc code=end

/*
fish：
两个节点形成环：包含在 这个情况里：for( ; s && f && f->next; s = s->next, f = f->next->next )
为什么快慢会相遇，因为慢的每次只移动一步，必然在s、f行进时会相遇。

*/

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 *
 * https://leetcode-cn.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (46.24%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    109.2K
 * Total Submissions: 236K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，判断链表中是否有环。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能用 O(1)（即，常量）内存解决此问题吗？
 * 
 */
