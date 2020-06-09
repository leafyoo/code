//linux, gcc
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <errno.h>  
#include <unistd.h> 
#include <sys/wait.h>
#include <time.h>

#include <iostream>  
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
 
using namespace std;

/* 
对输入的数组按出现的频率进行排序，若出现频率一致则按数字升序排序。
例如：1, 2, 4, 9, 4, 1, 4, 2, 结果为：4, 4, 4, 1, 1, 2, 2, 9

这道题，也可以用这样，
vector< pair<int, int> > vv;
然后，写一个compare函数

 */
void sortArrayByFrequency(vector<int> & v)
{
    map<int, int> mp;

    //如果要求出现频率相同按降序排列，那这里可以下面这样搞
    // map<int, int, greater<int>> mp;  
    for( int i = 0; i < v.size(); ++i)
    {
        ++mp[v[i]];
    }

    //这里是按照顺序来插入的，所以key相同的情况下，value是按照插入顺序来排序的，是稳定的（排序算法中的稳定性）
    multimap<int, int, greater<int> > mmp;
    for( map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        mmp.insert(make_pair(it->second, it->first));
    }

    int i = 0;
    for( multimap<int,int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
    {
        for( int j = 0; j < mp[ it->second ]; ++j)
        {
            v[i++] = it->second;
            cout << "-"<< v[i] << endl;
        }
    }
}

void _test_sortArrayByFrequency()
{
    vector<int> v = {2,2,4,4,4,1,1,5,5,5,3,3,3,0,0};
    sortByFrequency(v);
    for( int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
}

int main(int argc, char ** argv)
{
    _test_sortArrayByFrequency();

    return 0;
}






