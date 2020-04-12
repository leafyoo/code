// @lc code=start
class Solution {
    public:
     bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (x + y < z) return false;
        if (x == 0 || y == 0) return x+y == z;

        int divisor = maxComDivisor(x, y);
        if (z % divisor == 0) 
            return true;
        return false;
    }

    int maxComDivisor(int x, int y)     //求，x，y的最大公约数，等价于库函数 gcd(x, y)
    {
        for (int i = 2; i <= min(x, y); ++i)    //从2开始
        {
            if (x % i == 0 && y % i == 0) 
                return i;
        }
        
        return 1;
    }

};

/* 
fish：
【最大公约数】最大公因数，也称最大公约数、最大公因子，指两个或多个整数共有约数中最大的一个。
    例如：12、16的公约数有1、2、4，其中最大的一个是4，4是12与16的最大公约数，一般记为（12，16）=4。

x+y 是最大容量
ax+by=z 有解当且仅当 z 是 x, y 的最大公约数的倍数。因此我们只需要找到 x, y  的最大公约数并判断 z 是否是它的倍数即可。

我们可以认为每次操作只会给水的总量带来 x 或者 y 的变化量。因此我们的目标可以改写成：找到一对整数 a, b 使得

ax+by=z

而只要满足 z ≤ x+y，且这样的 a, b 存在，那么我们的目标就是可以达成的。

 */


// @lc code=end

/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 *
 * https://leetcode-cn.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (35.07%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 60.7K
 * Testcase Example:  '3\n5\n4'
 *
 * 有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
 * 
 * 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
 * 
 * 你允许：
 * 
 * 
 * 装满任意一个水壶
 * 清空任意一个水壶
 * 从一个水壶向另外一个水壶倒水，直到装满或者倒空
 * 
 * 
 * 示例 1: (From the famous "Die Hard" example)
 * 
 * 输入: x = 3, y = 5, z = 4
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 输入: x = 2, y = 6, z = 5
 * 输出: False
 * 
 * 
 */

