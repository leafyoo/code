// @lc code=start
bool comp(string &a, string &b)
{
    return a+b > b+a;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) 
    {
        int n = nums.size();
        string res;
        if(n < 1) return res;

        vector<string> vec;
        for( int i = 0; i < n; ++i)
            vec.push_back( to_string(nums[i]) );
        
        sort( vec.begin(), vec.end(), comp);        //错误：comp函数的定义放在class Solution里会报错

        for( int i = 0; i < vec.size(); ++i)
            res = res + vec[i];

        if( res[0] == '0' && res.size() > 1)        //处理 "00000"这种情况
            return "0";

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (35.75%)
 * Likes:    248
 * Dislikes: 0
 * Total Accepted:    25.2K
 * Total Submissions: 70.5K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

