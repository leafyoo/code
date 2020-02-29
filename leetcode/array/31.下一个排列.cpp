
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;

        int i = nums.size();
        int j = 0;
        for( j = i - 2; j >= 0; --j)
        {
            if(nums[j] < nums[j+1])
            {
                break;
            }
        }

        if(j < 0) 
            reverse(nums.begin(), nums.end());          //其实本质是要让右边的变成升序排列，但是恰好是降序，故只需reverse就好
        else
        {
            int k = 0;
            for( k = i - 1; k > j ; --k)
            {
                if ( nums[k] > nums[j] )
                {
                    break;
                }    
            }    

            swap(nums[j], nums[k]);
            reverse(nums.begin() + j+1 , nums.end());   //也可以：sort(nums.begin() + j+1 , nums.end());
        
        }
    }
    
};
// @lc code=end
/*
fish:
【总体思路】撸两遍找到两个标记点：
第一遍（找坑），从后往前，找到第一个降序的地方，标记为j；   【解释：因为从后往前 升序是最优的最小值，无可挑剔，不可能找出替换方法】
第二遍（找萝卜），从后往前，找到第一个比 a[j] 大的地方 k；    【解释：因为第一遍撸完，肯定j右边的都是从后往前升序的，所以只需要从后往前找，找到第一个比a[j]大的值swap，就可以确保这个值恰好是只比a[j] 大一点点，这个萝卜才是合适的萝卜】
好了，在标记点开始操作：
swap( a[j], a[k]);              【解释：萝卜入坑】
将j左侧的地方逆序；             【解释：“例如一个四位数，千分位的数比原先的大了，那百分位、十分位、个位无论怎么折腾，这个新的四位数也比之前的大，所以怎么刚好比之前的四位数大一点点呢？ 那就让低位的所有值重新排序为升序（因为前两遍撸的时候，都是按照升序规则，所以这里并不需要排序，只需要反转就好了）”】

【说明】
1、上文两处 reverse换成sort之后，照样通过，因为 ：其实本质是要让右边的变成升序排列，但是恰好撸的前提是升序，已经具备顺序了，所以只需要reverse就好了，这里reverse(nums.begin(), nums.end()) 换成 sort(nums.begin(), nums.end()) 之后照样通过。

*/
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.82%)
 * Likes:    387
 * Dislikes: 0
 * Total Accepted:    43.2K
 * Total Submissions: 131.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
