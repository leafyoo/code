// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int n = 0;
        
        do
        {
            n = (rand7() - 1) * 7 + rand7();      //错误：若rand7() * rand7() 执行超时，且得到的不是连续的数字   //这里会得到 1～49 之间的数
        }while (n > 40);      //因为40是10的倍数，所以最终概率相等

        return 1 + (n - 1) % 10;
    }
};
// @lc code=end
/* fish:
题解：

(rand7()−1)∗7 得到的集合 A 为  {0，7，14，21，28，35，42}
后面 rand7() 得到的集合B为 {1,2,3,4,5,6,7}


https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/xiang-xi-si-lu-ji-you-hua-si-lu-fen-xi-zhu-xing-ji/
 */

/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 *
 * https://leetcode-cn.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (47.44%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 10.9K
 * Testcase Example:  '1'
 *
 * 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
 * 
 * 不要使用系统的 Math.random() 方法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: 1
 * 输出: [7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 2
 * 输出: [8,4]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 3
 * 输出: [8,1,10]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * rand7 已定义。
 * 传入参数: n 表示 rand10 的调用次数。
 * 
 * 
 * 
 * 
 * 进阶:
 * 
 * 
 * rand7()调用次数的 期望值 是多少 ?
 * 你能否尽量少调用 rand7() ?
 * 
 * 
 */

