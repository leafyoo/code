// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for( int i = 0; i < nums.size(); ++i)
        {
            if(st.find(nums[i]) == st.end())
                st.insert(nums[i]) ;
            else
                st.erase(nums[i]);
        }

        return *(st.begin());               //错误：return st.begin();  iterator要解引用为int
    }
};

//数学解法：异或运算
class Solution_xor {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for( int i = 0; i < nums.size(); ++i)
        {
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end

/* 
fish
https://leetcode-cn.com/problems/single-number/solution/cxiang-xi-ti-jie-shuang-zhi-zhen-by-youlookdelic-3/

 */

/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (65.25%)
 * Likes:    1096
 * Dislikes: 0
 * Total Accepted:    159.1K
 * Total Submissions: 242.3K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */
