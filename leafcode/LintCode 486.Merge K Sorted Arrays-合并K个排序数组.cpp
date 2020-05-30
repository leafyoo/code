/*
多个有序数组合并
优先队列（小顶堆）
*/
struct node{
	int value;
	int out_index;//数组外索引
	int in_index;//数组内索引
	node(int v, int o,int i){
		value = v;
		out_index = o;
		in_index = i;
	}
	bool operator<(node a)const{
		return value < a.value;
	}
	bool operator>(node a)const{
		return value > a.value;
	}
};
vector<int> mergeSort(vector<vector<int>> &nums){
	vector<int> res;
	priority_queue <node, vector<node>,greater<node>> pq;
	int N = nums.size(), M = nums[0].size();

	//将每个数组的第一个元素（最小）放入小顶堆
	for (int k = 0; k < N; k++){
		pq.push(node(nums[k][0], k, 0));
	}
	int i = 0, j = 0;
	
    //优先队列满，取最小元素放入数组，然后将索引改为最小元素对应的数组中的索引
	while (res.size() < N*M){
		
		res.push_back(pq.top().value);////获得优先队列中最小值元素 存入目标数组

		i = pq.top().out_index;//最小值元素对应数组
		j = pq.top().in_index + 1;//最小值元素对应数组内下一个的元素
		pq.pop();
		if (j == M)//达到某数组末尾
		{
			pq.push(node(INFTY, i, j));
		}
		else
		{
			pq.push(node(nums[i][j], i, j));
		}
	}
	return res;
				
/* 
————————————————
版权声明：本文为CSDN博主「qiuye2014」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qiuye2014/java/article/details/86707126 


利用优先队列（即小顶堆）自动调整顺序的特点

将n个数组的第一个元素构建优先队列（小顶堆）
重复下列步骤n*m次：
每次从堆中取出最小元素（堆顶元素），并将其存入输出数组中
用堆顶元素所在数组的下一元素将堆顶元素替换掉，
如果数组中元素被取光了，将堆顶元素替换为无穷大。每次替换堆顶元素后，重新调整堆
————————————————
版权声明：本文为CSDN博主「qiuye2014」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qiuye2014/java/article/details/86707126

*/
/* 
将 k 个有序数组合并为一个大的有序数组。

样例
样例 1:

输入:
  [
    [1, 3, 5, 7],
    [2, 4, 6],
    [0, 8, 9, 10, 11]
  ]
输出: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
样例 2:

输入: 
  [
    [1,2,3],
    [1,2]
  ]
输出: [1,1,2,2,3]
挑战
在 O(N log k) 的时间复杂度内完成：

N 是所有数组包含的整数总数量。
k 是数组的个数。
————————————————
版权声明：本文为CSDN博主「小马哥MAX」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/majichen95/java/article/details/89632075
 */