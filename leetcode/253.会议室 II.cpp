// @lc code=start

//小根堆
class Solution_priority_queue {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size(), room = 1;
        if(n < 1) 
            return 0;

        sort(intervals.begin(), intervals.end());   //所有会议，按照开始时间排序
        
        //堆里只记录会议结束时间，堆顶是最小的结束时间（即最早结束的会议）
        priority_queue<int, vector<int>, greater<int> > pq;       //知识点：小顶堆
        pq.push( intervals[0][1] );
    
        for( int i = 1; i < n; ++i)
        {                                      //错误2：这里要注意是intervals[i][0]（会议开始时间）   而不是intervals[i][1]
            if(intervals[i][0] < pq.top())   //错误1：这里不是 <=， 因为结束和开始时同一个时间的话，可以复用会议室，这个和现实生活一样。
                ++room;
            else
                pq.pop();                     //找到了空的会议室，要把上一次会议结束时间更新（弹出）

            pq.push( intervals[i][1] );       //插入新增的会议的结束时间到堆
        }

        return room;
    }
};
/* 
https://leetcode-cn.com/problems/meeting-rooms-ii/solution/hui-yi-shi-ii-by-leetcode/
 */


//上下车问题解法：
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size(), room = 1;
        if(n < 1) return 0;

        vector<int> beg, end;               //将起点、终点时刻单独拎出来，弄成两个数组
        for( int i = 0; i < n; ++i)
        {
            beg.push_back( intervals[i][0] );
            end.push_back( intervals[i][1] );
        }

        sort(beg.begin(), beg.end());
        sort(end.begin(), end.end());

        for( int bi = 0, ei = 0, tmpRes = 0; bi < n && ei < n;  )
        {
            if(beg[bi] < end[ei])
            {
                ++tmpRes;
                ++bi;
            }
            else
            {
                --tmpRes;
                ++ei;                       //错误：这里写成了 --ei，错了
            }

            room = max(room, tmpRes);
        }

        return room;
    }
};
/* 
https://leetcode-cn.com/problems/meeting-rooms-ii/solution/253-hui-yi-shi-ii-c-shang-xia-che-wen-ti-by-gao-yu/
 */

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
