// @lc code=start

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int n = M.size();
        int res = 0;
        
        if(n < 1) 
            return 0;

        for( int i = 0; i < n; ++i) //总共有n名学生。  //这里为什么需要for？ 因为有孤岛，递归不能遍历完
        {
            if(M[i][i] == 1)        //直接找学生，为1说明还没有成为记录过的学生
            {
                mark(M, i);  //以这名学生开始遍历他的朋友
                ++res;
            }
        }

        return res;
    }

    void mark(vector<vector<int>>& M, int i)
    {
        if(M[i][i] == 0)  
            return ;
        M[i][i] = 0;                            //记录这个人已经遍历过,因为M[n][n]是必定等于1的，为0则说明已经遍历过
        
        for( int j = 0; j < M.size(); ++j)      //查找判断所有人，找出i的朋友
        {
            if(M[i][j] == 1)                    
            {
                mark(M, j);              //遍历其他同学，看看是否跟他是朋友 //找到n的朋友i，再递归查找i的朋友
            }
        }
    }

};

// @lc code=end
/* 
fish：整体是消除朋友的思想，有点贪婪、深度搜索的思想

https://leetcode-cn.com/problems/friend-circles/solution/547-peng-you-quan-tong-guo-dfshe-bing-cha-ji-javac/
 */


/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 *
 * https://leetcode-cn.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (55.63%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 54.8K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是
 * C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 * 
 * 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j
 * 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * 输出: 2 
 * 说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
 * 第2个学生自己在一个朋友圈。所以返回2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * 输出: 1
 * 说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
 * 
 * 
 * 注意：
 * 
 * 
 * N 在[1,200]的范围内。
 * 对于所有学生，有M[i][i] = 1。
 * 如果有M[i][j] = 1，则有M[j][i] = 1。
 * 
 * 
 */
