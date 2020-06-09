#include <iostream>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <errno.h>  

#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

string mySub(string A,string B)//只限两个非负整数
{
    string a, b; //a是大的
    int comp = A.compare(B);
    
    if( comp == 0)
        return string("0");
    if(B.size() > A.size())
    {
        a = B;
        b = A;
    }
    else if(A.size() > B.size())
    {
        a = A;
        b = B;
    }
    else if( comp < 0 )
    {
        a = B;
        b = A;
    }
    else
    {
        a = A;
        b = B;
    }

    string res;
    char va[1000] = {0};
    char vb[1000] = {0};
    int la = a.size();
    int lb = b.size();
    
    //倒序存储
    for (int i=0;i<la;i++)
        va[la-1-i] = a[i]-'0';
    
    //倒叙存储
    for (int i=0;i<lb;i++)
        vb[lb-i-1] = b[i]-'0';

    int lmax = max(la,lb);

    //从个位开始相减，va的第0位存着整个数字的最低位
    for (int i=0;i<lmax;i++)
    {
        va[i] -= vb[i];
        while (va[i]<0)
        {
            va[i] += 10;
            va[i+1]--;
        }
    }

    //处理前置0，即将高位的0去掉
    while (!va[lmax])
        lmax--;

    if (lmax < 0)
        res = "0";
    else 
    {
        for (int i = lmax; i >= 0; i--)
            res += va[i] + '0';
    }
    if(comp < 0)
        res = "-" + res;

    return res;
}

int main(int argc, char ** argv)
{
    cout << "arg1:" << argv[1] <<endl;
    cout << "arg2:" << argv[2] <<endl;
    cout << endl;

    cout << "res:"<< endl;
    cout << mySub(string( argv[1] ), string( argv[2]));


    return 0;
}


