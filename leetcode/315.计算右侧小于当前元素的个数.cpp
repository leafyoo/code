// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> lessCnt(n), sortVec;

        if(n == 0) 
            return lessCnt;
        
        for( int i = n-1; i >= 0; --i)
        {
            int b = 0, e = sortVec.size() - 1;
            for(; b <= e; )
            {
                int m = (b+e)/2;
                if(nums[i] <= sortVec[m])
                    e = m-1;
                else
                    b = m+1;
            }
            
            lessCnt[i] = e+1;
            sortVec.insert( sortVec.begin()+ lessCnt[i], nums[i]);
        }

        return lessCnt;
    }
};
 
/* 
作者：AdamWong
链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/ji-suan-you-ce-xiao-yu-dang-qian-yuan-su-de-ge-shu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */


class Solution_createBST {
public:
    struct Node{
        int val;
        int lNodeCnt;           //这个 也就是在nums数组种比val小的数的个数
        Node * l, *r;
        Node( int val ):val(val), lNodeCnt(0), l(nullptr), r(nullptr) {}
    };      //错误：这里少了 ；号

    void insert(Node *root, Node *newNode, int & lNodeCnt )
    {
        if(newNode->val <= root->val)           //错误：这里要包含 = ，从而下面的else不包含 = ，才是纯粹的比它小的元素的个数。
        {
            root->lNodeCnt++;                   /*【A】插入的结点更小,被比较结点(即  root )的count++，然后插入到左子树(如果不为空)*/
            if(root->l)
                insert( root->l, newNode, lNodeCnt);
            else
                root->l = newNode;              /*左子树为空，插入结点就作为当前结点的左孩子*/
        }
        else                                    /*插入的结点更大，需要在右子树(如果不为空)继续找*/
        {
            lNodeCnt += root->lNodeCnt + 1;     //【B】 更新当前节点的统计. 因为无法得知newNode的lNodeCnt，所以这里只是更新lNodeCnt
            if(root->r)
                insert( root->r, newNode, lNodeCnt);
            else
                root->r = newNode;              /*当前右子树为空，插入结点作为当前结点右孩子*/
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        int n = nums.size();
        set<Node *>st;

        /*建立一个二叉搜素树*/
        Node *root = new Node(nums[ n - 1]);
        st.insert(root);
        res.push_back(0);
        for( int i = n-2; i >=0 ; --i)
        {
            int lNodeCnt = 0;
            Node *newNode = new Node(nums[ i ]);
            st.insert(newNode);

            insert( root , newNode, lNodeCnt);
            res.push_back(lNodeCnt);
        }

        /*最后不要忘记删除树节点*/
        for( set<Node *>::iterator it = st.begin(); it != st.end(); ++it)
            delete *it;

        reverse(res.begin(), res.end());            /*push_back的时候是逆序的，此时只要将count数组reverse即可*/

        return res;
    }
};
/* 
fish：
这个方案太占内存了。容易错的点太多了。

https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/ji-suan-you-ce-xiao-yu-dang-qian-yuan-su-de-ge-shu/

 */

// @lc code=end

/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (37.40%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 31.4K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于
 * nums[i] 的元素的数量。
 * 
 * 示例:
 * 
 * 输入: [5,2,6,1]
 * 输出: [2,1,1,0] 
 * 解释:
 * 5 的右侧有 2 个更小的元素 (2 和 1).
 * 2 的右侧仅有 1 个更小的元素 (1).
 * 6 的右侧有 1 个更小的元素 (1).
 * 1 的右侧有 0 个更小的元素.
 * 
 * 
 */
