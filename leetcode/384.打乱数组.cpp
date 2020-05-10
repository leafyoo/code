// @lc code=start
class Solution {
    vector<int> mNums;
    vector<int> backup;
public:
    Solution(vector<int>& nums) {
        this->mNums = nums;
        this->backup = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        mNums = backup;
        return mNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int end = mNums.size() - 1; end >= 0; --end) {      //为什么要从倒数开始？ 下面rand时方便一点
            int randI = rand() % (end + 1);          //如nums：[1,2,3,4]，end=4-1=3, end+1=4, randI:0,1,2,3
            swap(mNums[randI], mNums[end]);          //[0,1,2,3 ...,end, ... n-1 ]  ，在0~end之间随机选一个和end交换
        }
        return mNums;
    }
};
/* 一般来说，对于一个问题我通常会给出两种以上的解法，但是对于洗牌问题，Fisher-Yates 洗牌算法即是通俗解法，同时也是渐进最优的解法。 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 *
 * https://leetcode-cn.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (50.12%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 34.4K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * 打乱一个没有重复元素的数组。
 * 
 * 示例:
 * 
 * 
 * // 以数字集合 1, 2 和 3 初始化数组。
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
 * solution.shuffle();
 * 
 * // 重设数组到它的初始状态[1,2,3]。
 * solution.reset();
 * 
 * // 随机返回数组[1,2,3]打乱后的结果。
 * solution.shuffle();
 * 
 * 
 */
