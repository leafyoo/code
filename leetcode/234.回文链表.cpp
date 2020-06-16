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
    bool isPalindrome(ListNode* head) {
        if(!head) 
            return true;  //leetcode将 空两边也当做回文链表了，所以这里返回true

        ListNode *s = head, *f = head;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }

        s = reverse(s);
        for(; head && s; head = head->next, s = s->next)
        {
            if(head->val != s->val)
                return false;
        }
        return true;
    }

    ListNode * reverse(ListNode *h)
    {
        ListNode *p = nullptr;
        while( h )
        {
            ListNode *t = h->next;  //指针赋值，S型赋值
            h->next = p;
            p = h;
            h = t;
        }    

        return p;
    }
};
// @lc code=end

/* 
fish:
如果明确说明不能改变链表，那就用栈。

 */


/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.35%)
 * Likes:    397
 * Dislikes: 0
 * Total Accepted:    63K
 * Total Submissions: 155.9K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */
