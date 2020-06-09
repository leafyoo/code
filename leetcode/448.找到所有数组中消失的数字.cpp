

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for( int i = 0; i < nums.size(); )
        {
            if(nums[i] == i +1 || nums[i] == nums[ nums[i]-1 ])     //nums[i] == nums[ nums[i]-1 ] 这个是为了避免重复swap
                ++i;
            else
                swap(nums[i], nums[ nums[i]-1 ]);
        }
        for( int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1) 
                v.push_back( i+1);          //【相似】类似于 442题，只是这里不同
        }

        return v;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (56.13%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 47.6K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [5,6]
 * 
 * 
 */