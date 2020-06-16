// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10) 
            return num;
        
        vector<int> v;
        for( int i = num ; i > 0;  )
        {
            v.insert( v.begin(), i % 10);
            i = i/10;
        }

        //step 1： 找临界点：高区、低区转折点 （降序 到  升序）
        int idx = -1;
        for( int i = 0; i < v.size()-1 ; ++i)
        {
            if(v[i] < v[i+1])
            {
                idx = i+1;
                break;
            }
        }
        if(idx == -1) 
            return num;   //即全部为降序

        //step 2： 在低区中查找，找到低区的最大值
        int lowMaxIdx = idx, highMinIdx = 0;
        for( int i = idx+1; i < v.size(); ++i)
        {
            if(v[i] >= v[lowMaxIdx])         //例如7588，所以要取等号 
                lowMaxIdx = i;    //上面 v[lowMaxIdx] 的值会实时更新，相当于记录了最大值了，没必要单独变量来记录了
        }

        //step 3： 在高区中查找，找到第一个比低区最大值小的地方，然后交换
        for( int i = 0; i < idx; ++i)
        {
            if(v[i] < v[lowMaxIdx])
            {
                swap(v[i], v[lowMaxIdx]);
                break;
            }
        }

        //step 4：整理数组
        num = 0;
        for(int i = 0 ; i< v.size(); ++i  )
            num = num * 10 + v[i];

        return num;
    }
};
// @lc code=end
/*
fish:
【思路】分成高区，低区，要从低区里找出一个最大值MAX，拿来和高区里第一个比MAX小的位置交换。
1，先将数每一位拆成数组
2，找临界点：高区、低区转折点 （从降序 变为 升序） （因为：若数组为非升序序列，则直接返回原数即可）
3，在低区中查找，找到低区的最大值
4，在高区中查找，找到第一个比低区最大值大的地方，然后交换

链接：https://leetcode-cn.com/problems/maximum-swap/solution/c-ti-jie-by-da-li-wang-12/

*/


/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 *
 * https://leetcode-cn.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (38.48%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 9.9K
 * Testcase Example:  '2736'
 *
 * 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
 * 
 * 示例 1 :
 * 
 * 
 * 输入: 2736
 * 输出: 7236
 * 解释: 交换数字2和数字7。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: 9973
 * 输出: 9973
 * 解释: 不需要交换。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数字的范围是 [0, 10^8]
 * 
 * 
 */


//这个版本两个for循环，时间复杂度太高了
class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10) return num;

        vector<int> v;
        for( int i = num ; i > 0;  )
        {
            v.insert( v.begin(), i % 10);
            i = i/10;
        }

        int im = 0, jm = 0, maxDiff = 0;
        for( int i = 0; i < v.size()-1 ; ++i)
        {
            for( int j = i+1; j < v.size(); ++j)
            {
                if ( maxDiff <= v[j] - v[i] )
                {
                    maxDiff = v[j] - v[i];
                    im = i;
                    jm = j;
                }
            }

            if ( maxDiff > 0 )break;          //错误，不能漏了这步，千分位找到了目标，百分位当然不用考虑了
        }
        
        if(maxDiff > 0)
        {
            swap(v[im], v[jm]);

            num = 0;
            for(int i = 0 ; i< v.size(); ++i  )
            {
                num = num * 10 + v[i];
            }
        }

        return num;
    }
};