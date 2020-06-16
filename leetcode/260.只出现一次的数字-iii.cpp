// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.empty()) 
            return {};
        unordered_set<int> st;
        
        for( int i = 0; i < nums.size(); ++i)
        {
            if( !st.insert(nums[i]).second )            //错误：少了.second， insert的返回值为pair，pair的second是结果
                st.erase( nums[i]);
        }

        return vector<int>( st.begin(), st.end());
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 *
 * https://leetcode-cn.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (70.66%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    16.6K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
 * 
 * 示例 :
 * 
 * 输入: [1,2,1,3,2,5]
 * 输出: [3,5]
 * 
 * 注意：
 * 
 * 
 * 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
 * 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
 * 
 * 
 */
