// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;

        sort(nums.begin(), nums.end());
        
        for( int i = 0; i <= n-4; ++i)
        {
            while( i>0 && i <= n-4 && nums[i] == nums[i-1]) ++i;         //去重1：保第1/4个元素不重复    //这里如果用continue可以避免判断上面的for循环里的条件
            for( int j = i+1; j <= n-3; ++j)
            {
                while( j >i+1 && j <= n-3 && nums[j] == nums[j-1]) ++j;  //去重2：保第2/4个元素不重复    

                int k = j+1, l = n-1;        
                while( k < l )
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];    //这里赋值给sum，使得下文可读性更高
                    if(sum < target)    
                    {
                        ++k;
                        while(k < l && nums[k] == nums[k-1]) ++k;       //去重3：保第3/4个元素不重复
                    }
                    else if(sum > target)    
                    {
                        --l;
                        while(k < l && nums[l] == nums[l+1]) --l;       //去重4：保第4/4个元素不重复
                    }
                    else if(sum == target)    
                    {
                        res.push_back( {nums[i], nums[j], nums[k], nums[l]} );      //知识点：四个元素的vector的构造方法
                        ++k;
                        while(k < l && nums[k] == nums[k-1]) ++k;
                        --l;
                        while(k < l && nums[l] == nums[l+1]) --l;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end
/* 
fish：思路基本同三数之和，无非是多了一个外循环 for j。
题解：
https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/

 */


/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.17%)
 * Likes:    405
 * Dislikes: 0
 * Total Accepted:    62.4K
 * Total Submissions: 167.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
