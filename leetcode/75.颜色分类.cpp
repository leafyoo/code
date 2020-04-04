// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        multiset<int> ms(nums.begin(), nums.end());
        nums.assign(ms.begin(), ms.end());
    }
};




class Solution_vector {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt( 3 , 0);                //用于记录 0、1、2分别出现多少次
        for( int i = 0; i < n; ++i)
            cnt[ nums[i] ]++;

        nums.clear();
        for( int i = 0; i < cnt.size(); ++i)
        {
            for( int j = 0; j < cnt[ i ]; ++j)
                nums.push_back( i );
        }
    }
};
// @lc code=end

/* 
https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-he-lan-qi-zhi-liang-tang-sao-miao-f/
 */


/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (54.70%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    68.5K
 * Total Submissions: 125.2K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

