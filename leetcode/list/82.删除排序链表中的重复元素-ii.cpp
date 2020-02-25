// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
思路：
如下图，p和q都是能先不迈出一步就不迈出，
更新p和q的 next指针算一步，
更新p、q又算一步，
整体是两个循环：吸星大法。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode prehead(0);                    //这里要给构造函数初始值 val的 0 ，否则编译不通过
        ListNode * p = &prehead, *q = head;
        p->next = head;
        
        for( ; p && q && q->next; )         //外循环的继续条件：根据无重复数据的情况来，也可以在主逻辑写完之后再写这里 【首次摸石头过河，针对p】
        {
            if (q->val == q->next->val)
            {
                while(q->next && q->val == q->next->val)    //陷入吸星大法  【二次摸石头过河，针对q】
                {
                    q->next = q->next->next;                //q不动，只更新next
                }
                q = q->next;
                p->next = q;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }

        return prehead.next;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (45.76%)
 * Likes:    220
 * Dislikes: 0
 * Total Accepted:    32.3K
 * Total Submissions: 70.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 * 
 */


