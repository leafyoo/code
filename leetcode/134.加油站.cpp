// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ng = gas.size(), nc = cost.size();
        
        if(!ng || !nc || ng != nc) 
            return -1;
        
        //注意stl算法的使用accumulate   //错误：少了第三个参数 ,0
        if(accumulate(gas.begin(), gas.end() ,0) < accumulate(cost.begin(), cost.end(),0 ))   
            return -1;

        int minGasSum = INT_MAX, minIdx = 0, gasSum = 0; 
        for( int i = 0; i < ng; ++i)
        {
            gasSum += gas[i] - cost[i];
            if(gasSum < minGasSum)
            {
                minGasSum = gasSum;
                minIdx = i;
            }
        }

        return (minIdx + 1) % ng;       //注意技巧：循环数组的下标溢出处理   // 错误：这里是minIdx + 1，因为，上面gasSum其实是走到i+1站点时油量的消耗
    }
};
/* 
fish:
题解（如下面的链接）：
以该题为例：
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

然后，黑色的曲线是整体的趋势，都和从站点1出发的趋势一致，，
从其他不同的站点出发，仅仅是相当于站点1的起点不同而已，也就是黑色线的纵坐标方向做了平移而已。
所以，肯定黑线要全在x轴以上，那就是最低点在x轴以上。

https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/


每个站点对全局油量的贡献数组为：
contribution ：
[-2,-2,-2,3,3]


 */


class Solution_force {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ng = gas.size(), nc = cost.size();
        if(!ng || !nc ) return -1;
        
        int beg = 0;
        for( ; beg < ng; ++beg )
        {
            int cnt = 0, cur = beg, gasSum = 0;
            for( ; cnt < ng; ++cnt )
            {
                gasSum = (gasSum + gas[ cur ] - cost[ cur ]);
                if(gasSum >= 0)
                {
                    ++cur;
                    cur = (cur > ng-1 ) ? 0 : cur;          //错误：cur = (cur == ng-1 ) ? 0 : cur+1; ，这里是ng-1，而不是ng
                }
                else
                    break;
            }
            if( cnt >= ng)
                return beg;
        }

        return -1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 *
 * https://leetcode-cn.com/problems/gas-station/description/
 *
 * algorithms
 * Medium (50.89%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    25.1K
 * Total Submissions: 48.9K
 * Testcase Example:  '[1,2,3,4,5]\n[3,4,5,1,2]'
 *
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 * 
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 * 
 * 说明: 
 * 
 * 
 * 如果题目有解，该答案即为唯一答案。
 * 输入数组均为非空数组，且长度相同。
 * 输入数组中的元素均为非负数。
 * 
 * 
 * 示例 1:
 * 
 * 输入: 
 * gas  = [1,2,3,4,5]
 * cost = [3,4,5,1,2]
 * 
 * 输出: 3
 * 
 * 解释:
 * 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
 * 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
 * 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
 * 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
 * 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
 * 因此，3 可为起始索引。
 * 
 * 示例 2:
 * 
 * 输入: 
 * gas  = [2,3,4]
 * cost = [3,4,3]
 * 
 * 输出: -1
 * 
 * 解释:
 * 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
 * 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
 * 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
 * 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
 * 因此，无论怎样，你都不可能绕环路行驶一周。
 * 
 */
