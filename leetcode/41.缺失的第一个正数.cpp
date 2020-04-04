// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();

        for( int i = 0; i < n; ++i)
        {
            //错误：溢出： nums[i] - 1 会溢出：-2147483648 - 1 cannot be 
            while(nums[i] != i+1 )       //交换之后，nums[i]跑到后面合适的位置，但当前位置跑来的数不一定是应该在当前的，所以需要不断交换
            {
                long long newIdx = (long long)nums[i] - 1;      //避免nums[i] - 1溢出
                if( newIdx < 0 || newIdx >= n || nums[i] == nums[ newIdx ])     //注意：避免死循环： nums[i] == nums[ newIdx ]
                    break;
                swap(nums[i], nums[ newIdx ]);
            }
        }

        for( int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
                return i+1;
        }

        return n+1;
    }

};
/* fish
https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/
要找的数一定在 [1, N + 1] 左闭右闭（这里 N 是数组的长度）这个区间里。（不理解？举例demo一下就知道了）
因此，我们可以就把原始的数组当做哈希表来使用。事实上，哈希表其实本身也是一个数组；
我们要找的数就在 [1, N + 1] 里，最后 N + 1 这个元素我们不用找。因为在前面的 N 个元素都找不到的情况下，我们才返回 N + 1；
那么，我们可以采取这样的思路：就把 1 这个数放到下标为 0 的位置， 2 这个数放到下标为 1 的位置，
按照这种思路整理一遍数组。然后我们再遍历一次数组，第 1 个遇到的它的值不等于下标的那个数，就是我们要找的缺失的第一个正数。

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


错误1：
while(nums[i] - 1 != i )   要改为： while(nums[i] != i+1 )  

Line 7: Char 27: runtime error: signed integer overflow: -2147483648 - 1 cannot be represented in type 'int' (solution.cpp)

 */

// @lc code=end
/* fish：
https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/
 */



/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (37.76%)
 * Likes:    433
 * Dislikes: 0
 * Total Accepted:    43.3K
 * Total Submissions: 114.4K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 * 
 */

