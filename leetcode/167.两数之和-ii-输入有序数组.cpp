// @lc code=start
class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int b = 0, e = numbers.size()-1;

        while( b < e )
        {
            if(numbers[b] + numbers[e] == target)
                return {b+1, e+1};
            else if(numbers[b] + numbers[e] < target)
                ++b;
            else
                --e;
        }
        return{-1, -1};
    }
};
// @lc code=end

/*
fish:  双指针法 （注意，不存在收缩后又需要吃回头草的情况！！！
因为两个靠左的数之和肯定大于两个靠右的数的和  ）


对于这类题，要从两边着手，然后，考虑什么情况下变化下标。

这个陷入误区了，详见文件末尾
*/

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (52.49%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    68.3K
 * Total Submissions: 129.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */
/*

下面这个未通过：暂时跳过：

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int b = 0, e = numbers.size()-1,mid = target/2, m = 0;
        while( b < e )
        {
            m = (b + e)/2;
            if(numbers[m] == mid)
                break;
            if(numbers[m] > mid)
                e = m - 1;
            else
                b = m + 1;
        }

        if(2 * numbers[m] == target)
        {
            if(m -1 >=0 && numbers[m - 1] ==numbers[m] ) return{m, m+1};
            if(m +1 < numbers.size() && numbers[m ] == numbers[m+1] ) return{m+1, m+2};
        }    
        else if(2 * numbers[m] < target)
        {
            b = m;
            e = m+1;
        }    
        else
        {
            b = m - 1;
            e = m;
        }

        while( b < e && e < numbers.size() && b >=0)
        {
            if(numbers[b] + numbers[e] == target)
                return {b+1, e+1};
            else if(numbers[b] + numbers[e] < target)
                ++e;
            else
                --b;
        }

        return{-1, -1};
    }
};
*/