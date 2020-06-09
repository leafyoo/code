
// @lc code=start

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());         //先sort

        for( int i = 0; i < nums.size(); ++i)
        {
            int b = i+1, e = nums.size() -1;
            while( b < e )
            {
                int sum = nums[i] + nums[b] +nums[e];
                if(sum == 0) 
                {
                    res.push_back({nums[i] ,nums[b], nums[e]});     //知识点：三个元素的数组的创建方法
                    while( b< e && nums[b] == nums[b+1]) ++b;       //去重1：对第二位置的重复考察。是否和下一个位置相同
                    while( b< e && nums[e] == nums[e-1]) --e;       //去重2：对第三位置的重复考察。是否和下一个位置相同
                    ++b;        //因为上面已经push_back，已经选用过了，所以这里要再进一步跳过重复值。
                    --e;
                }
                else if(sum < 0)
                    ++b;
                else
                    --e;
            }

            while( i+1 < nums.size() && nums[i] == nums[i+1]) ++i;  //去重3：对第一位置的重复考察
        }
        return res;
    }
};

// @lc code=end
/*
fish：
去重的理解，例如去重3，因为已经考察过i在当前值的情况下，b、e的所有组合，下次如果还是考察i在当前值的情况，结果一样。


错误：
if(i>0 && nums[i] == nums[i-1])             //错误：这里改成这样不行： if(i+1 < nums.size() && nums[i] == nums[i+1])  continue; 
因为这样会导致b没有机会尝试部分值。

*/
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.51%)
 * Likes:    1837
 * Dislikes: 0
 * Total Accepted:    160.9K
 * Total Submissions: 627.9K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */


/*
错误case：重复太多，超时。

Time Limit Exceeded
312/313 cases passed (N/A)
Testcase
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

class Solution_set {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for( int i = 0; i < nums.size(); ++i)
        {
            int b = i+1, e = nums.size() -1;
            while( b < e )
            {
                int sum = nums[i] + nums[b] +nums[e];
                if(sum == 0) 
                {
                    s.insert({nums[i] ,nums[b], nums[e]});
                    ++b;
                    --e;
                }
                else if(sum < 0)
                    ++b;
                else
                    --e;
            }
        }
        res.assign(s.begin(), s.end());
        return res;
    }
};
*/