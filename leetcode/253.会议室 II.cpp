// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size(), res = 1;
        if(n < 1) return 0;

        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int> > pque;       //知识点：小顶堆
        pque.push( intervals[0][1] );
    
        for( int i = 1; i < n; ++i)
        {                                      //错误2：这里要注意是intervals[i][0]（会议开始时间）   而不是intervals[i][1]
            if(intervals[i][0] < pque.top())   //错误1：这里不是 <=， 因为结束和开始时同一个时间的话，可以复用会议室，这个和现实生活一样。
            {
                ++res;
            }
            else
            {
                pque.pop();                     //找到了空的会议室，要把上一次会议结束时间更新（弹出）
            }
            pque.push( intervals[i][1] );
        }

        return res;
    }
};
// @lc code=end

/* fish：
题解提交在这里：
https://leetcode-cn.com/problems/meeting-rooms-ii/submissions/

 */

/*
 * @lc app=leetcode.cn id=253 lang=cpp
 *
 * [253] 会议室 II
 *
 * https://leetcode-cn.com/problems/meeting-rooms-ii/
 *
 * 253. 会议室 II
 * 给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 
 * [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑充分利用会议室资源，
 * 请你计算至少需要多少间会议室，才能满足这些会议安排。
 * 
 * 示例 1:
 * 
 * 输入: [[0, 30],[5, 10],[15, 20]]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[7,10],[2,4]]
 * 输出: 1
 * 通过次数5,655提交次数13,546
 * 
 * 
 */
