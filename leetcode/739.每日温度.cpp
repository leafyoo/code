// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        stack<int> st;

        for( int i = n-1; i >= 0; --i)
        {
            while(!st.empty() && T[i] >= T[st.top()])       //错误1：>=少了=。 错误2：st.top()只是下标而已，要转换成T
                st.pop();

            res[ i ] = (st.empty() ? 0 : (st.top() - i)) ;
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (58.29%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 54.3K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */