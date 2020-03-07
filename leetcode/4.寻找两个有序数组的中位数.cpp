// @lc code=start
/*
if nums1[k / 2 - 1] < nums2 [k / 2 - 1]
then the nums1[k / 2 - 1] and it's left side elements must smaller than kth number in num arrary(num[k - 1]).
*/

/*
beg: b
end: e
vector :  v
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int k = (v1.size() + v2.size()) / 2;
        double mid = getKthofTwoArr(v1, 0, v1.size(),    v2, 0, v2.size(),    k + 1);
        
        if ((v2.size() + v1.size()) % 2 == 0)          //偶数个，中位数有两个
        {
            int midAnother  = getKthofTwoArr(v1, 0, v1.size(),    v2, 0, v2.size(),    k);
            return (mid + midAnother) * 0.5;                 //错误：这里不可以是 mid = (mid + midAnother) * 0.5;上文 mid如果是int，会丢掉小数
        }
        
        return mid;
    }

    int getKthofTwoArr(vector<int> & v1, int b1, int e1,    vector<int> & v2, int b2, int e2,    int k)
    {
        int len1 = e1 - b1;
        int len2 = e2 - b2;
        if (len1 > len2) return getKthofTwoArr(v2, b2, e2,    v1, b1, e1,    k);  //使得 v1长度 < v2长度

        else if (len1 == 0)                 //这个在先，则下文就不用判断v1会否越界了
            return v2[b2 + k - 1];
        else if (k == 1)
            return min(v1[b1], v2[b2]);
        else 
        {
            int skip1 = min (k / 2, len1);//if nums1[k / 2 - 1] < nums2 [k / 2 - 1]then ... 如上文注释
            int skip2 = k - skip1;
            
            if (v1[b1 + skip1 - 1] == v2[b2 + skip2 - 1])           //v1和v2的两个左半边加起来刚好是K个
                return v1[b1 + skip1 - 1];
            else if (v1[b1 + skip1 - 1] < v2[b2 + skip2 - 1])       //压缩问题规模：v1的skip1之前的部分可以不用考虑了，裁减掉了
                return getKthofTwoArr(v1, b1 + skip1, e1,   v2, b2,           e2,       k - skip1); //递归，k减小了，v1的规模也减小了
            else
                return getKthofTwoArr(v1, b1,         e1,   v2, b2 + skip2,   e2,       k - skip2);
        }
    }

};
// @lc code=end
/*
fish: 思路 ，压缩问题规模
*/
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.82%)
 * Likes:    2184
 * Dislikes: 0
 * Total Accepted:    144.5K
 * Total Submissions: 392.1K
 * Testcase Example:  '[1,3]\len2[2]'
 *
 * 给定两个大小为 len1 和 len2 的有序数组 v1 和 v2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(len1 + len2))。
 * 
 * 你可以假设 v1 和 v2 不会同时为空。
 * 
 * 示例 1:
 * 
 * v1 = [1, 3]
 * v2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * v1 = [1, 2]
 * v2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

