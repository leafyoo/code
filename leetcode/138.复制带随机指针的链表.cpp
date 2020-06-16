
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
*/
//fishyoo：此题可以用哑结点，理解更容易一点
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) 
            return nullptr;

        unordered_map<Node *, Node *> mp;

        Node prehead(0);
        Node *p = head, *pre = &prehead;

        for( ; p ; p = p->next )
        {
            //1、创建新拷贝节点： p 
            if ( !mp.count(p) )
                mp[p] = new Node(p->val);

            //2、创建新拷贝节点： p->random 
            if ( p->random )            //注意判断非空
            {
                if ( !mp.count(p->random) )
                    mp[p->random] = new Node(p->random->val);
                
                mp[p] -> random = mp[p->random];     //3、关联random，即将新拷贝节点：p、p->random 关联起来。           
            }

            //4、新的拷贝链表指针更新
            pre->next = mp[p];
            pre = pre->next;
        }

        return prehead.next;
    }

};
// @lc code=end

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (44.14%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 44K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]\r'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 
 * 要求返回这个链表的 深拷贝。 
 * 
 * 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 * 
 * 
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 * 
 * 
 * 示例 4：
 * 
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10000 <= Node.val <= 10000
 * Node.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 * 
 * 
 */


/* 

    //无哑结点版本：
    Node* copyRandomList_noDummy(Node* head) {
        if(!head) return NULL;

        unordered_map<Node*, Node*> mp; //map[ 旧的节点地址 ] = 新的拷贝节点地址。 如此，则mp[p] 即新的拷贝节点的地址指针。
        Node *p = head, *pNew = NULL;
        
        for(; p; p = p->next)
        {
            //1、创建新拷贝节点： p 
            if(!mp.count(p))                
                mp[p] = new Node(p->val);                       

            //2、创建新拷贝节点： p->random 
            if(p->random)
            {
                if(!mp.count(p->random))    
                    mp[p->random] = new Node(p->random->val);   

                //3、关联random，即将新拷贝节点：p、p->random 关联起来。
                mp[p]->random = mp[p->random];                  
            }

            //4、新的拷贝链表指针更新
            if(pNew)   
                pNew->next = mp[p];
            pNew = mp[p];            //即：移动到下一个节点
        }

        return mp[head];
    }
 */