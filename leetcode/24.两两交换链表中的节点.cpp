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
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(0);
        ListNode *p = &prehead, *q = head, *t = nullptr;
        p->next = head;

        for( ; q && q->next;  )
        {
            t = q->next;                        //这里用了哑结点，赋值情况和链表反转的不一样
            q->next = t->next;
            t->next = p->next;
            p->next = t;

            //上面都只是更新了next指针，这里要更新p的值
            p = q; //或者 p = p->next->next;
            q = q->next;
        }

        return prehead.next;
    }
};

class Solution_digui 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)      ///终止条件为所有都交换完了的链表
            return head;
        ///递归单元内两个节点做交换
        //定义一个p结点为head->next(该递归单元内第二个节点)
        
        //【待提交】
        ListNode *nextH         = head->next->next;       //记录第三个节点同时也是下一次递归的head
        ListNode *newH          = head->next;
        
        head->next->next        = head;         //使此单元内第二个节点指向第一个节点，即交换位置
        head->next              = swapPairs(nextH);  //交换完成后的head应指向下一次单元返回的头节点
        
        return newH;   //返回该单元的头节点
    }
};
/* 
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/di-gui-die-dai-dong-zhong-wen-jiu-ying-gai-neng-li/
来源：力扣（LeetCode）
 */


// @lc code=end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.27%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    71.4K
 * Total Submissions: 111.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */
