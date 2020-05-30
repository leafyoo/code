/*
1. 给定一个排序链表，删除所有重复的元素，只留下原链表中没有重复的元素。例如:
1) 1->2->3->3->4->4->5->null, return: 1->2->5->null
2) 1->1->1->2->3->null, return: 2->3->null
3) 1->2->3->4->4->null, return: 1->2->3->null

struct LinkNode {
  int value;
  struct LinkNode * next;
};
struct LinkNode* delete_duplicates(struct LinkNode* head);
*/

#include <iostream>
using namespace std;
struct LinkNode {
  int value;
  struct LinkNode * next;
};
struct LinkNode* delete_duplicates(struct LinkNode* head)
{
  if(!head || !head->next)
  {
    return head;
  }
    
  struct LinkNode *p = NULL, *q = NULL;
  struct LinkNode Pre;
  p = &Pre;
  p ->next = head;
  q = head;
  
  while( q && q->next )
  {
    if(q && q->next && q->value == q->next->value)
    {
      while(q && q->next && q->value == q->next->value)
      {
        q->next = q->next->next;
      }
      
      q = q->next;
      p->next = q;
    }
    else
    {
      
      q = q->next;
      p = p->next;
    }
  }
  
  return Pre.next;
}


int _test_delete_duplicates() {
  struct LinkNode a, b, c, d, e, f, g;
 
/*
1) 1->2->3->3->4->4->5->null, return: 1->2->5->null
2) 1->1->1->2->3->null, return: 2->3->null
3) 1->2->3->4->4->null, return: 1->2->3->null

*/
/*
  a.next = NULL;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = NULL;
  f.next = NULL;
  g.next = NULL;
    
  a.value = 1;
  b.value = 2;
  c.value = 3;
  d.value = 4;  
  e.value = 4;
  f.value = 4;    
  g.value = 5; 
*/

  a.next = &;
  b.next = NULL;
  c.next = &d;
  d.next = &e;
  e.next = NULL;
  f.next = NULL;
  g.next = NULL;
    
  a.value = 1;
  b.value = 2;
  c.value = 3;
  d.value = 4;  
  e.value = 4;
  f.value = 4;    
  g.value = 5; 

/*
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = NULL;
  f.next = NULL;
  g.next = NULL;
    
  a.value = 1;
  b.value = 2;
  c.value = 3;
  d.value = 4;  
  e.value = 4;
  f.value = 4;    
  g.value = 5;  
*/
  
/*  
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;
  f.next = &g;
  g.next = NULL;
    
  a.value = 1;
  b.value = 2;
  c.value = 3;
  d.value = 3;  
  e.value = 4;
  f.value = 4;    
  g.value = 5;
*/
/*
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = NULL;
  f.next = NULL;
  g.next = NULL;
    
  a.value = 1;
  b.value = 1;
  c.value = 1;
  d.value = 2;  
  e.value = 3;
  f.value = 4;    
  g.value = 5;  
*/  
  
  struct LinkNode *p = &a;
  while(p)
  {
    cout<< p->value << endl;
    p = p->next;
  }  
  
  cout<< "end" << endl;
  
  p = delete_duplicates(&a);
  while(p)
  {
    cout<< p->value << endl;
    p = p->next;
  }  
  
    return 0;
}


/*
3. 对输入的数组按出现的频率进行排序，若出现频率一致则按数字升序排序。
例如：1, 2, 4, 9, 4, 1, 4, 2, 结果为：4, 4, 4, 1, 1, 2, 2, 9

void sort(int arr[], int n);
*/
#include <iostream>
#include <map>
//#include <multimap>

using namespace std;
void sortByFreq(int arr[], int n)
{
  map<int, int> mp;
  for(int i = 0; i< n; ++i)
  {
    ++mp[arr[i]];
    cout << i << "-" << endl;
  }
  
  multimap<int, int, greater<int> > mmp;
  for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
  {
    mmp.insert( make_pair(it->second, it->first));
    //cout << it->first << "--"<< it->second  << endl;
  }
  
  int i = 0;
  for(multimap<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
  {
    for(int j = mp[it->second]; j > 0; --j)
    {
    arr[i++] = it->second;
    //cout << i << "---" << it->second<< endl;      
    }
    
  }
  
}

int _test_sortByFreq()
{
  int arr[] = { 1,2,4,9,4,1,4,2};
  sort(arr, sizeof(arr)/sizeof(arr[0]));
  
  for(int i = 0; i< sizeof(arr)/sizeof(arr[0]); ++i)
  {
    cout << i << ":" <<arr[i] << endl;
  }  
  
  return 0;
}



/*
2. 给一个由数字组成的字符串，求出所有可能的 IP 地址。
例如：给出字符串 "25525511135"，所有可能的 IP 地址为：
[  "255.255.11.135", "255.255.111.35"  ]
vector<string> restore_ip_addrs(const string& s);
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<string> res;



bool check(string s)
{
  if( (s.size() < 1 || s.size() > 3)
  || (stoi(s) > 255 || stoi(s) < 0)
  || (s.size() > 1 && s[0] == '0') )
  {
    return false;
  }
  else
  {
    return true;
  }
}


void dfs(string tail, int cnt, string ip)
{
  if(tail.empty() || cnt == 4)
  {
    if(tail.empty() && cnt == 4)
      res.push_back(ip);
    return;
  }
  
  for(int i = 1; i <= 3; ++i)
  {
    string str;
    
    if(tail.size() < i || !check(tail.substr(0, i)))
      break;
      
    string app = (cnt == 3) ? 
      tail.substr(0, i) : (tail.substr(0, i) + ".");
    
    dfs(tail.substr(i), cnt+1, ip + app);
  }
  
  return;
}


vector<string> restore_ip_addrs(const string& s)
{
  int sLen = s.size();
  if(sLen < 4 || sLen > 12) //"1.1.1.1", 
    return res;
  
  dfs(s, 0, string(""));
  
  return res;
}

int _test_restore_ip_addrs()
{
  vector<string> v;
  
  //v = restore_ip_addrs( string("25525511135"));
  //v = restore_ip_addrs( string(""));
  //v = restore_ip_addrs( string("25425511135"));
  //v = restore_ip_addrs( string("255255255255"));
  v = restore_ip_addrs( string("1111"));
  for(int i = 0; i < v.size() && i < 10; ++i)
  {
    cout << v[i] << endl;
  }
  
  return 0;
}