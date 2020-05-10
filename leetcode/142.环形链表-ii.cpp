
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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;  //一个节点成环也被这里考虑到了，因为head->next == head 而不是null

        ListNode *s = head, *f = head;    //s: slow, f: fast
        while( f && f->next )
        {
            s = s->next;
            f = f->next->next;
            
            if(s == f)              //有环了，则陷入处理
            {
                f = head;           //fast指针重新从头出发
                while( s != f )     //这里要判断s和f是否已经相等了，然后才能继续同步走，否则，对于2节点的循环判断出错，例如这个  1<-->2
                {
                    f = f->next;
                    s = s->next;
                }

                return f;
            }
        }

        return nullptr;
    }
};
// @lc code=end
/* fish
//参见：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
 
 当 fast 指针走到f = a  步时，slow 指针走到步s = a+nb ，此时 两指针重合，并同时指向链表环入口 。

 */


/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (48.41%)
 * Likes:    364
 * Dislikes: 0
 * Total Accepted:    51.4K
 * Total Submissions: 106K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 说明：不允许修改给定的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：tail connects to node index 1
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：tail connects to node index 0
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：no cycle
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 你是否可以不用额外空间解决此题？
 * 
 */