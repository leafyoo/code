/*
4. 给出一组非负整数，重新排列他们的顺序把他们组成一个最大的整数。最后的结果可能很大，所以我们返回一个字符串来代替这个整数。
例如：给出 [1, 20, 23, 4, 8]，返回组合最大的整数应为8423201。

char* largest_number(int* nums, int numsSize);
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(string &a, string &b)
{
  return a+b > b+a;
}

char* largest_number(int* nums, int numsSize)
{
  vector<int> v(nums, nums + numsSize);
  int n = v.size();
  string res;
  
  if(n < 1) return (char*)res.c_str();
  
  vector<string> vec;
  for(int i = 0; i < n; ++i)
    vec.push_back( to_string(v[i]) );
  
  sort(vec.begin(), vec.end(), cmp);
  
  for(int i = 0; i < vec.size(); ++i)
    res = res + vec[i];
  
  if(res.size() > 1 && res[0] == '0')
    return 0;
  
  return ( char*)res.c_str();
}

/*
例如：给出 [1, 20, 23, 4, 8]，返回组合最大的整数应为8423201。
*/
int main()
{
  int arr[] = {1, 20, 23, 4, 8};
  cout << largest_number(arr, sizeof(arr)/sizeof(arr[0]));
  
  return 0;
}