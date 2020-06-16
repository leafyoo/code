#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <stdexcept>
using namespace std;


/*
首先01背包题目的雏形是:有N件物品和一个容量为V的背包。
第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。

f[i][v] = max{f[i-1][v],  f[i-1][v-c[i]] + w[i]}

f[v] = max{f[v],  f[v-c[i]] + w[i]};

fish：
上面是如何简化成下面的？？因为等式右边是 f[i-1]状态，即前一个状态的，而等式左边是f[i]，即当前状态的

方程之中，现在需要放置的是第i件物品，这件物品的体积是c[i],价值是w[i],
因此f[i-1][v]代表的就是不将这件物品放入背包，而f[i-1][v-c[i]]+w[i]则是代表将
第i件放入背包之后的总价值，比较两者的价值，得出最大的价值存入现在的背包之中。
http://www.tuicool.com/articles/nIn2u2E

*/
int package01(int num, int capacity, int weiArr[], int priceArr[])
{
	if(num < 1 || capacity < 1 || !weiArr || !priceArr)
		return 0;
	int *dp = new int[capacity + 1]();				//价值
	for(int i = 0; i < num; ++i)					//对于每一个物品，在每一种容量情况下
	{
		for(int cap = capacity; cap >= weiArr[i]; --cap)//在每一种容量情况下 物品i放入与不放入时的最大价值。
		{
			dp[cap] = max(dp[cap], dp[cap - weiArr[i]] + priceArr[i]);	//放入，或者 不放入，取最大值。
		}	//总容量cap时，对应的最大的价值
	}
	return dp[capacity];
}
void _test_package01()
{
	int weiArr[] = {1,2};
	int priceArr[] = {5,3};
	cout << package01(2, 2, weiArr, priceArr);
}


int main()
{

	return 0;
}
