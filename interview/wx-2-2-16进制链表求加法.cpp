/*
1. 有两个由链表表示的数字，数字为 16 进制（用 0-9, a-f表示，如 1a9d），请返回两数之和，返回值也用链表表示。例如：
  数 a: 5->3, 表示数字 35; 数 b: 2->4->3, 表示数字 342
  返回: 7->7->3, 即 377.
  struct Digit {
      char n;
      Digit* next;
  };
Digit* sum(const Digit* a, const Digit* b);
*/


/* 
https://codeinterview.io/playback/WMDOFPUZRM#?t=3361

 */
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Digit {
    char n;
    Digit* next;
};
  
inline int getHex( char c)
{
  if(c >= 'a' && c <= 'f')
  {
    return 10 + c - 'a';
  }
  
  if(c >= '0' && c <= '9')
  {
    return c - '0';
  }
  
  return 0;
}

Digit* sum(const Digit* a, const Digit* b)
{
  Digit* p =( Digit*)a, *q =( Digit*)b;
  Digit preH;
  Digit* h = &preH;
  
  int up = 0;
  
  while( p || q)
  {
    h->next = new Digit;
    h = h->next;

    int x = (p ? getHex(p->n) : 0);
    int y = (q ? getHex(q->n) : 0);
 
    h->n = (x+y+up)%16;
    up = (x+y+up)/16;
    
    p = (p ? p->next : p);
    q = (q ? q->next : q);  

  }
  
  if(up)
  {
    h->next = new Digit;
    h = h->next;
    h->n = up;
  }
  
  return preH.next;
}

/*
  数 a: 5->3, 表示数字 35; 数 b: 2->4->3, 表示数字 342
  返回: 7->7->3, 即 377.
  
  */
int main() {
  Digit preH, preH2;
  Digit* h = &preH, *h2 = &preH2;
  
  
  h->next = new Digit; 
  h = h->next;
  h->n = 'f'; 
  h->next = NULL;

  h->next = new Digit; 
  h = h->next;
  h->n = 'f'; 
  h->next = NULL;  
  
  h2->next = new Digit; 
  h2 = h2->next;
  h2->n = '1'; 
  h2->next = NULL;
    
  Digit* newH = sum((const Digit*)(preH.next), (const Digit*)( preH2.next) );
  
  while(newH)
  {
    cout << (int)newH->n << endl;
    newH = newH->next;
  }
  
	//cout<<"Hello";
	return 0;
}
