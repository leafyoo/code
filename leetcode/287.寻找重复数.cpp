// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        
        int begVal = 1, endVal = n;           //错误：begVal = 1  //注意：这里begVal 和 endVal是value，不是index
        while( begVal < endVal )
        {
            int cnt = 0, midVal = (begVal+endVal)/2;
            for( int i = 0; i < nums.size(); ++i)       //每次都是遍历整个数组, 统计小半区里的数字的个数
            {
                if(nums[i] <= midVal)        //错误：这里是 <=
                    ++cnt;
            }
            if(cnt > midVal)
                endVal = midVal;              // 重复元素位于区间 [left, mid]
            else
                begVal = midVal + 1;          // [mid + 1, right]
        }

        return begVal;
    }
};

// @lc code=end
/* 
//fish：这个题不同于传统的二分法，传统的二分法处理index，而这里处理的是value的范围
/*区间 [1, 7] 的中位数是 4，遍历整个数组，统计小于等于 4 的整数的个数，至多应该为 4 个。换句话说，整个数组里小于等于 4 的整数的个数如果严格大于 4 个，就说明重复的数存在于区间 [1, 4]，它的反面是：重复的数存在于区间 [5, 7]。

于是，二分法的思路是先猜一个数（有效范围 [left, right]里的中间数 mid），然后统计原始数组中小于等于这个中间数的元素的个数 cnt，如果 cnt 严格大于 mid，（注意我加了着重号的部分“小于等于”、“严格大于”）依然根据抽屉原理，重复元素就应该在区间 [left, mid] 里。

链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/

 */
/* 
fish:
解法2：sort，之后遍历。

抽屉原理
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/

例子：
index:  0 1 2 3 4
value: [1,3,4,3,3]

 */


/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (63.45%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    42.6K
 * Total Submissions: 67.1K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 * 
 * 
 */
