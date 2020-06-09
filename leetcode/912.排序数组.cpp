// @lc code=start

// 插入排序 
/**
 * <插入排序>
思路：每次将一个数字插入一个有序的数组里，成为一个长度更长的有序数组，有限次操作以后，数组整体有序。
特点：「插入排序」可以提前终止内层循环（体现在 tmp < nums[j] 不满足时），在数组「几乎有序」的前提下，「插入排序」的时间复杂度可以达到 O(N)；
应用：由于「插入排序」在「几乎有序」的数组上表现良好，特别地，在「短数组」上的表现也很好。因为「短数组」的特点是：每个元素离它最终排定的位置都不会太远。
为此，在小区间内执行排序任务的时候，可以转向使用「插入排序」。

链接：https://leetcode-cn.com/problems/sort-an-array/solution/fu-xi-ji-chu-pai-xu-suan-fa-java-by-liweiwei1419/


 * 时间复杂度: 最好O(n) 最坏O(n^2) 平均O(n^2) 稳定
 * 空间复杂度: O(1)
 */
// class Solution {
class Solution_insert {
public:
    vector<int> sortArray(vector<int>& nums) {
        for( int i = 1, j = 0; i < nums.size(); ++i)
        {
            int tmp = nums[i];

            for( j = i-1; j >= 0 && tmp < nums[j]; --j)     //这里不能写成 tmp <= nums[j]， 否则成了不稳定算法
                nums[j+1] = nums[j];                        //比两两交换更高效。
            
            nums[j+1] = tmp;
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

思想来源：插入排序的优化。在插入排序里，如果靠后的数字较小，它来到前面就得交换多次。「希尔排序」改进了这种做法。带间隔地使用插入排序，直到最后「间隔」为 1 的时候，就是标准的「插入排序」，此时数组里的元素已经「几乎有序」了；

 */
// class Solution {
class Solution_shell {
public:
    vector<int> sortArray(vector<int>& nums) {
        for( int gap = nums.size()/2; gap > 0; gap /= 2 )
        { 
            for( int i = gap; i < nums.size(); ++i) //i：代表j的上限
            {
                for( int j = i-gap; j >=0 && nums[j+gap] < nums[j]; j -= gap)       //j -= gap，因为shell排序的优势就是跨距离消除逆序
                    swap(nums[j], nums[j+gap]);
            }
        }

        return nums;
    }
};

/**
 * <选择排序>
 思路：每一轮选取未排定的部分中最小的部分交换到未排定部分的最开头，经过若干个步骤，就能排定整个数组。即：先选出最小的，再选出第 2 小的，以此类推。
 
 * 时间复杂度: 最好O(n^2) 最坏O(n^2) 平均O(n^2) 稳定
 * 空间复杂度: O(1)
 * 优点：交换次数最少。
「选择排序」看起来好像最没有用，但是如果在交换成本较高的排序任务中，就可以使用「选择排序」
 */
// class Solution {
class Solution_select {
public:
    vector<int> sortArray(vector<int>& nums) {

        // 循环不变量：[0, i) 有序，且该区间里所有元素就是最终排定的样子
        for( int i = 0; i < nums.size() - 1; ++i)
        {
             // 选择区间 [i, len - 1] 里最小的元素的索引，交换到下标 i
            int minIdx = i;
            for( int j = i+1; j < nums.size(); ++j)     //这里无条件循环，所以，时间复杂度最好最坏均是O(n2)
            {
                if( nums[j] < nums[minIdx])
                    minIdx = j;
            }

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

堆排序是选择排序的优化，选择排序需要在未排定的部分里通过「打擂台」的方式选出最大的元素（复杂度 O(N)O(N)），而「堆排序」就把未排定的部分构建成一个「堆」，这样就能以 O(\log N)O(logN) 的方式选出最大元素；

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
                ++maxSon;
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
fish:堆排序的思想
排序步骤：
1)首先输出堆顶元素（因为它是最值），将堆顶元素和最后一个元素（无序区）交换。这样，第n个位置（即最后一个位置）作为有序区，前n-1个位置仍是无序区，对无序区进行调整；
2)得到堆之后，再交换堆顶和最后一个元素，这样有序区长度变为2。。。
3)如此循环交换堆顶与最后一个元素，将剩下的元素重新调整为堆，然后输出堆顶元素到有序区。每次交换都导致len（无序区） - 1，len（有序区） + 1。
4)不断重复此过程直到有序区长度增长为n-1，排序完成。

从0开始计算 i节点的子节点为 2*i+1, 2*i+2 

图片：https://leetcode-cn.com/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/

 */

/**
 * <冒泡排序>
 * 时间复杂度: 最好O(n) 最坏O(n^2) 平均O(n^2) 稳定
 * 空间复杂度: O(1)
基本思想：外层循环每一次经过两两比较，把每一轮未排定部分最大的元素放到了数组的末尾；

「冒泡排序」有个特点：在遍历的过程中，提前检测到数组是有序的，从而结束排序，而不像「选择排序」那样，即使输入数据是有序的，「选择排序」依然需要「傻乎乎」地走完所有的流程。
*/
//冒泡排序 ： 每次都从头开始，----> ，俩俩比较，每一轮都会使得最大的元素移动到无序区的最后面。 一轮后至少确保较小的数都有往前挪了一步。
// class Solution {
class Solution_bubble {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        for( int i = n-1; i >= 0 ; --i)
        {
            for( int j = 0; j < i; ++j)         //可见：每一轮的最终位置在前移，也即是一个最大元素会浮动到最后面去
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
 * 空间复杂度: O(log(n))  这里占用的空间主要来自递归函数的栈空间。
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
        if(b >= e) return;  //左右指针相遇

        swap( nums[ (b+e)/2 ], nums[e]);    //增加随机性,若数组有序,不替换复杂度为O(n^2),这里基准数为nums[e]

        //这里做的工作都是为了下面的   swap(nums[t], nums[e]);     
        int t = b;                         // 最右侧节点的值nums[e] 应该 在数组中的位置t，t之左全比nums[e]小
        for( int i = b; i < e; ++i)
        {
            if(nums[i] < nums[e])               //nums[t]之前的数都小于等于nums[e], 但是nums[t] 大于nums[e]
            {
                swap(nums[i], nums[t]);  //找到一个比nums[e]小的，那就把他调到前面去
                ++t;                        //i这里比e那里还小，那就在往
            }
        }
        swap(nums[t], nums[e]);       //此时t所指的位置即为num[e]在数组中 最终的位置

        quickSort(nums, b, t-1);
        quickSort(nums, t+1, e);
    }
};
/* 
fish：
思想：
1、每次找数组中一个标杆值，然后在数组中找出这个标杆值的最终位置 t，然后把标杆值nums[e]调配到 t里来。
2、分治，对t 之前和之后两个区间分别采用同样的思路，递归下去。

 */

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
            if(backup[i] <= backup[j])               //// 注意写成 < 就丢失了稳定性（相同元素原来靠前(beg部分)的排序以后依然靠前）
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


//非比较的排序：
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

/* fish：各种排序的讲解：
https://leetcode-cn.com/problems/sort-an-array/solution/fu-xi-ji-chu-pai-xu-suan-fa-java-by-liweiwei1419/


 */