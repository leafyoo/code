
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return target;

        sort(nums.begin(), nums.end());   

        int res = nums[0] + nums[1] + nums[2]; 
        for( int i = 0; i < nums.size(); ++i)
        {
            int b = i+1, e = nums.size()-1;
            while( b < e )
            {
                int sum = nums[b] + nums[e] + nums[i];
                if( sum < target )
                    ++b;
                else if ( sum > target )
                    --e;

                res = abs(target - sum) < abs(target - res)  ? sum : res; 
                if(res == target) return res;
            }
        }

        return res;
    }
};
// @lc code=end
/*
fish:

1、时间复杂度：因为要计算三个数，如果靠暴力枚举的话时间复杂度会到 O(n^3)，需要降低时间复杂度
首先进行数组排序，时间复杂度 O(nlogn) 
整个遍历过程，固定值为 n 次，双指针为 n 次，时间复杂度为 O(n^2)
总时间复杂度：O(nlogn) + O(n^2) = O(n^2)


2、题解：
https://leetcode-cn.com/problems/3sum-closest/solution/hua-jie-suan-fa-16-zui-jie-jin-de-san-shu-zhi-he-b/

*/


/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 174.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

/*

*/
class Solution_v0 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return target;

        sort(nums.begin(), nums.end());   

        int res = nums[0] + nums[1] + nums[2]; 
        for( int i = 0; i < nums.size(); ++i)
        {
            int b = 0, e = nums.size()-1; //b如果没有从i+1开始，下面就需要各种处理i e b  相等的情况
            while( b < e )
            {
                if(b == i)++b;
                if(e == i)--e;
                if(b >= e) break;
                
                int sum = nums[b] + nums[e] + nums[i];

                if( sum < target )
                    ++b;
                else if ( sum > target )
                    --e;

                res = abs(target - sum) < abs(target - res)  ? sum : res; 
                if(res == target) return res;
            }
        }

        return res;
    }
};