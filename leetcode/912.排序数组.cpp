// @lc code=start

// 插入排序 
/**
 * <插入排序>
 * 时间复杂度: 最好O(n) 最坏O(n^2) 平均O(n^2) 稳定
 * 空间复杂度: O(1)
 */
// class Solution {
class Solution_insert {
public:
    vector<int> sortArray(vector<int>& nums) {
        for( int i = 1, j = 0; i < nums.size(); ++i)
        {
            for( j = i-1; j >= 0 && nums[j+1] < nums[j]; --j)         //错误：tmp写成了 nums[j+1] ，是给tmp在有序前缀中找插入位置
                swap(nums[j+1] , nums[j] );
        }

        return nums;
    }
};
/* 
Time Limit Exceeded
9/10 cases passed (N/A)
 */


//希尔排序
/**
 * <希尔排序> / <缩小增量排序>
 * 时间复杂度: 平均O(n^1.3) 不稳定
 * 空间复杂度: O(1)
 * 特点: 缩小增量的插入排序
 */
// class Solution {
class Solution_shell {
public:
    vector<int> sortArray(vector<int>& nums) {
        for( int gap = nums.size()/2; gap > 0; gap /= 2 )
        { 
            for( int i = gap; i < nums.size(); ++i)
            {
                for( int j = i-gap; j >=0 && nums[j+gap] < nums[j]; j -= gap)       //j -= gap
                    swap(nums[j], nums[j+gap]);
            }
        }

        return nums;
    }
};

/**
 * <选择排序>
 * 时间复杂度: 最好O(n^2) 最坏O(n^2) 平均O(n^2) 稳定
 * 空间复杂度: O(1)
 */
// class Solution {
class Solution_select {
public:
    vector<int> sortArray(vector<int>& nums) {
        for( int i = 0; i < nums.size() - 1; ++i)
        {
            int minIdx = i;
            for( int j = i+1; j < nums.size(); ++j)     //这里无条件循环，所以，时间复杂度最好最坏均是O(n2)
            {
                if( nums[j] < nums[minIdx])
                    minIdx = j;
            }

            if(i != minIdx)
                swap(nums[minIdx], nums[i]);
        }

        return nums;
    }
};
/* 
Time Limit Exceeded
9/10 cases passed (N/A)
 */


/**
 * <堆排序>
 * 时间复杂度: 最好O(n*log(n)) 最坏O(n*log(n)) 平均O(n*log(n)) 不稳定
 * 空间复杂度: O(1)
 */
//堆排序
// class Solution {
class Solution_heap {
public:
    void down(vector<int>& nums, int beg, int end)  //父节点下沉
    {
        int parentVal = nums[beg];
         int maxSon = 2*beg + 1;        // 左孩子
        while( maxSon <= end )          //i = e时，也要和子节点比较调整，所以勿漏=
        {
            if(maxSon+1 <= end && nums[maxSon+1] > nums[maxSon])        //在左右孩子中找最大的
                maxSon = maxSon + 1;
            if(parentVal >= nums[maxSon])
                break;
            
            nums[beg] = nums[maxSon];       //把较大的子结点往上移动,替换i的父结点  
            beg = maxSon;
            maxSon = 2*maxSon + 1;
        }
        nums[beg] = parentVal;              //将旧堆顶赋给后面的节点
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        for( int i = n/2 - 1; i >= 0; --i)      // a[len/2 - 1]为堆的最后一个非叶子节点
            down(nums, i, n-1);                 //从下往上一圈一圈逐渐变大

        for( int i = n-1; i > 0; --i)           //>0
        {
            swap(nums[0], nums[i]);
            down(nums, 0, i-1);                 //[0..i-1]重新调整为大顶堆 
        }

        return nums;
    }
};
/* 
从0开始计算 i节点的子节点为 2*i+1, 2*i+2 
 */

/**
 * <冒泡排序>
 * 时间复杂度: 最好O(n) 最坏O(n^2) 平均O(n^2) 稳定
 * 空间复杂度: O(1)
    */
//冒泡排序 ： 每次都从头开始，往后前进，俩俩比较，一轮后至少确保较小的数都有往前挪了一步。
// class Solution {
class Solution_bubble {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        for( int i = n-1; i >= 0 ; --i)
        {
            for( int j = 0; j < i; ++j)
            {
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }

        return nums;
    }
};
/* 
Time Limit Exceeded
9/10 cases passed (N/A)
 */

//冒泡排序优化：
/*
仅前面len个无序，那么在第一趟遍历后,
最后发生交换的位置必定小于len，
记录下这位置，第二次只要从数组头部遍历到这个位置就可以了
*/
class Solution_bubble_v2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        for(int end = n-1, change = n-1; change > 0 ; )
        {
            end = change;
            change = -1;                        //重置change
            for( int j = 0; j < end; ++j)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                    change = j;
                }
            }
        }

        return nums;
    }
};


/**
 * <快速排序>
 * 时间复杂度: 最好O(n*log(n)) 最坏O(n^2) 平均O(n*log(n)) 不稳定
 * 空间复杂度: O(log(n))
 * 特点: 本质是给基准数找其正确位置的过程.
 */
/* 
如果上面不按照中间节点为基准，则如果本身有序，每次分界递归，总是一半只有一个，另一半又有很多，
导致递归次数变多（递归n次）,效率变差，并且每次递归里有一个for循环，所以复杂度变为 n^2。
而如果每次从中间均分，递归，递归的次数是O（logn），复杂度为O(n*logn)
 */
/*
原理:
一次可以确保一个元素位置是最终位置:即，其左边都比他小，右边都比他大。
然后递归重复。左边作为标志，右边先开始扫描，再左边开始扫描
*/
class Solution_quick {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        quickSort(nums, 0, n-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int b, int e)
    {
        if(b >= e) return;

        swap( nums[ (b+e)/2 ], nums[e]);    //增加随机性,若数组有序,不替换复杂度为O(n^2),这里基准数为nums[e]
        int mid = b;
        for( int i = b; i < e; ++i)
        {
            if(nums[i] < nums[e])
                swap(nums[i], nums[mid++]);
        }
        swap(nums[e], nums[mid]);

        quickSort(nums, b, mid-1);
        quickSort(nums, mid+1, e);
    }
};


/**
 * <归并排序>
 * 时间复杂度: 最好O(n*log(n)) 最坏O(n*log(n)) 平均O(n*log(n)) 稳定
 * 空间复杂度: O(n)
 */
class Solution_merge {
public:
    vector<int> backup; //备份数组

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;
        backup.resize(n);                   //错误：漏掉了设置大小
        mergeSort(nums, 0, n-1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int beg, int end)
    {
        if(beg >= end) return;  //只剩一个，已经有序，不必再分
        int mid = (beg+end)/2;
        mergeSort(nums, beg, mid);  
        mergeSort(nums, mid+1, end);
        merge(nums, beg, mid, end);     //[beg, mid]和[mid+1, end]都排好序了，合并它们
    }

    void merge(vector<int>& nums, int beg, int mid, int end)
    {
        for(int i = beg; i <= end; i++)             //先备份数组，因为下面会对nums赋值，覆盖掉原数据
            backup[i] = nums[i];            
        
        int i = beg, j = mid+1, k = beg;            //这里不要用for，用i++的形式更清晰
        while( i <= mid && j <= end )
        {
            if(backup[i] < backup[j])               //用backup对比大小
                nums[k++] = backup[i++];
            else
                nums[k++] = backup[j++];
        }
        while( i <= mid )                           //继续使用上面的i、k、j的值
            nums[k++] = backup[i++];
        while( j <= end )
            nums[k++] = backup[j++];
    }

};

/* 
基数排序：
https://leetcode-cn.com/problems/sort-an-array/solution/c-8chong-pai-xu-fang-fa-xiang-jie-by-zsq/
 */

// @lc code=end


/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (52.64%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    18.8K
 * Total Submissions: 35.4K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给定一个整数数组 nums，将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * -50000 <= A[i] <= 50000
 * 
 * 
 */