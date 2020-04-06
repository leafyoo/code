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
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( !l1 || !l2) return (l1 ? l1 : l2);

        ListNode prehead(0);
        ListNode * p = & prehead;
        for( ; l1 && l2; p = p->next)
        {
            if ( l1->val < l2->val )
            {
                p->next = l1;       //这里只是改变了p->next这个指针的指向，p的指向还没变
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
        }
        if ( l1 || l2 )
        {
            p->next = (l1 ? l1 : l2);
        }
        return prehead.next;
    }

     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) 
            return nullptr;

        ListNode* head = lists[0];
        for(int i = 1; i<lists.size(); ++i)
        {
            if(lists[i]) 
                head = mergeTwoLists(head, lists[i]);
        }
        return head;  
    }
    
    // 合并两个有序链表，递归
    ListNode* mergeRecursive(ListNode* p1, ListNode* p2)
    {
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val)
        {
            p1->next = mergeRecursive(p1->next, p2);
            return p1;      //注意这里要return
        }
        else
        {
            p2->next = mergeRecursive(p1, p2->next);
            return p2;
        }
    }    
};
/* fish： 从上往下，每次合并一行 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.80%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    74.4K
 * Total Submissions: 152.3K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 * 
 */


/* 

有时运行超时，有时通过：

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode prehead(0);
        ListNode *p = &prehead;
        while(1){
            int min = INT_MAX;               //【欲求最小，赋其最大】找最小值，所以初始值要搞为最大值
            vector<ListNode*>::iterator it = lists.begin(), itMin = lists.end();//注意，是修改vector的元素，不是修改数值。要用迭代器
            for( ;it != lists.end();  ++it)
            {
                // if( !(*it) )it = lists.erase(it);    //这里删除会引起下文itMin迭代器失效

                if ((*it) && (*it)->val <= min )
                {
                    min = (*it)->val;
                    itMin = it;
                }
            }
            if( itMin == lists.end() )break;    //循环结束的条件尽量靠前放

            p->next = *itMin;
            p = p->next;
            (*itMin) = (*itMin)->next;          //更新vector中存储的list头
        }

        return prehead.next;
    }
};
 */