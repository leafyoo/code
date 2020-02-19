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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode prehead(0);
        ListNode *p = &prehead;
        while(1){
            int min = 0x7fffffff;   //找最小值，所以初始值要搞为最大值
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
            (*itMin) = (*itMin)->next; //更新vector中存储的list头
        }

        return prehead.next;
    }
};
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
