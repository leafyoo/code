// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};
/* 
fish:
因此，要想获胜，在你的回合中，必须避免石头堆中的石子数为 4 的情况。

同样地，如果有五块、六块、或是七块石头，你可以控制自己拿取的石头数，总是恰好给你的对手留下四块石头，使他输掉这场比赛。

链接：https://leetcode-cn.com/problems/nim-game/solution/nimyou-xi-by-leetcode/

 */


class Solution_dfs {
public:
    bool canWinNim(int n) {
        if(n <= 0) {
            return false;
        }
        if(n <= 3) {
            return true;
        }
        return !canWinNim(n-1) || !canWinNim(n-2) || !canWinNim(n-3);
    }
};

// @lc code=end

/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 *
 * https://leetcode-cn.com/problems/nim-game/description/
 *
 * algorithms
 * Easy (69.69%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    42K
 * Total Submissions: 60.4K
 * Testcase Example:  '4'
 *
 * 你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
 * 
 * 你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: false 
 * 解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
 * 因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
 * 
 * 
 */

