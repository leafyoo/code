/*
2. 某操作系统采用 LRU 作为内存页面置换算法。
    假设初始内存为空，现给定将访问的内存页序列 pages, 序列长度 page_cnt 和内存总容量(页面数) mem，请返回缺页中断的次数。
    例如：序列 pages = 1, 2, 3, 2, 1, 4; 内存 mem = 2
    返回：5
    int check_page_faults(int pages[], int page_cnt, int mem);
*/
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int check_page_faults(int pages[], int page_cnt, int mem)
{
  int res = 0;
  list<int> lst;
  
  for(int i = 0; i < page_cnt; ++i)
  {
    if(lst.size() < mem)
    {
      if( find(lst.begin(),lst.end(), pages[i]) == lst.end() )
      {
        lst.push_front( pages[i] );
        ++res;
      }
    }
    else
    {
      if(  find(lst.begin(),lst.end(), pages[i]) == lst.end() )
      {
        lst.pop_back();
        lst.push_front( pages[i] );
        ++res;
      }      
    }
  }
  
  return res;
}

int main()
{
  int pages[] = {1, 2, 3, 4, 5, 1};
  cout << check_page_faults( pages, sizeof(pages)/sizeof(pages[0]), 1);
  return 0;
}