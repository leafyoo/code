// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();

        vector<int> res(n);
        stack<int> st;

        for( int i = n-1; i >= 0; --i)      //维护一个：单调栈。  里头记录着数组的下标
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

/* fish：【单调栈】 的思想

我们试着找到 T[0] 过后温度升高的位置。如果知道 T[10]=50，则 T[20]=50 是无效信息，因为 T[i] 在 T[20] 以前已经到达了 50。
因此，我们需要记住一个索引的列表，索引代表的温度【严格递增】。我们可以利用栈来实现这样的效果。


我们用栈记录索引，满足 T[stack[-1]] < T[stack[-2]] < ...，其中 stack[-1] 是栈的顶部，stack[-2] 是从顶部开始的第二个元素，依此类推；我们将在处理每个 T[i] 时保持 stack[-1] > stack[-2] > ...。
我们通过当前温度和栈顶索引所代表的温度比较来找到温度升高的位置。
举个例子：我们反向遍历处理 t=[73，74，75，71，69，72，76，73] ，通过看栈元素的变化来理解是如何工作的。为了清楚 stack 只包含索引 i，但是将把 T[i] 的值写在旁边的括号中，例如 0 (73)。
当 i = 7，stack = [7 (73)]。ans[i] = 0。
当 i = 6，stack = [6 (76)]。ans[i] = 0。
当 i = 5，stack = [5 (72), 6 (76)]。ans[i] = 1。
当 i = 4，stack = [4 (69), 5 (72), 6 (76)]。ans[i] = 1。
当 i = 3，stack = [3 (71), 5 (72), 6 (76)]。ans[i] = 2。
当 i = 2，stack = [2 (75), 6 (76)]。ans[i] = 4。
当 i = 1，stack = [1 (74), 2 (75), 6 (76)]。ans[i] = 1。
当 i = 0，stack = [0 (73), 1 (74), 2 (75), 6 (76)]。ans[i] = 1。

作者：LeetCode
链接：https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */


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