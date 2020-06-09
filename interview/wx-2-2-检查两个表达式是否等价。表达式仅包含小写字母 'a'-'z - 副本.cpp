/*
3. 检查两个表达式是否等价。表达式仅包含小写字母 'a'-'z', '+', '-', '(', ')'，且表达式里的未知数仅有一个字符。
例如：
1) exp1 = "a+b+c-a", exp2 = "(b+c)", result: true
2) exp1 = "a-b-c", exp2 = "a-(b+c)", result: true
3) exp1 = "a-b+c", exp2 = "a-(b+c)", result: false
4) exp1 = "a-b+c", exp2 = "a-(b-(c-d)-d)", result: true
5) exp1 = "a+d", exp2 = "b+c", result: false

bool check(const char* exp1, const char* exp2);
*/
#include <iostream>    
#include <string>
#include <stack>
#include <vector>
 
using namespace std;

void getSum(string &s, vector<int> &v)
{
    stack<int> st;
    int sign = 1;
        
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == '(')
        {
            int preSign = (s[i-1] == '-' ? -1 : 1);
            sign *= preSign;
            st.push(preSign);
        }
        else if(s[i] == ')')
        {
            sign /= st.top();
            st.pop();
        }        
        else if( s[i] >= 'a' && s[i] <= 'z')
        {
            int idx = s[i] - 'a';
            v[ idx ] += sign * (s[i-1] == '-' ? -1 : 1) ;
        }
    } 
}

bool check(const char* exp1, const char* exp2)
{
    string s1(exp1), s2(exp2);
    s1 = "+" + s1;
    s2 = "+" + s2;
    
    vector<int> v1(26, 0), v2(26, 0);
    
    getSum(s1, v1);
    getSum(s2, v2);
    
    return (v1 == v2);
}

int main(int argc, char ** argv)
{
    string s1, s2;

    /* test case 1: */
    s1 = "a+b+c-a";
    s2 = "(b+c)";
    cout << s1 << "\t\t\t == " << s2 << "\t\t\t:" << check(s1.c_str(), s2.c_str() ) << endl;

    /* test case 2: */
    s1 = "a-b-c";
    s2 = "a-(b+c)";
    cout << s1 << "\t\t\t == " << s2 << "\t\t\t:" << check(s1.c_str(), s2.c_str() ) << endl;

    /* test case 3: */
    s1 = "a-b+c";
    s2 = "a-(b+c)";
    cout << s1 << "\t\t\t == " << s2 << "\t\t\t:" << check(s1.c_str(), s2.c_str() ) << endl;

    /* test case 4: */
    s1 = "a-b+c";
    s2 = "a-(b-(c-d)-d)";
    cout << s1 << "\t\t\t == " << s2 << "\t\t\t:" << check(s1.c_str(), s2.c_str() ) << endl;
    
    /* test case 5: */
    s1 = "a+d";
    s2 = "b+c";
    cout << s1 << "\t\t\t == " << s2 << "\t\t\t:" << check(s1.c_str(), s2.c_str() ) << endl;
    
    return 0;
}