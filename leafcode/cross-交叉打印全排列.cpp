#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<vector<char> > res;
vector<char> path;
int total;

void DFS(string a, string b )
{
    if(path.size() == 8)
    {
        res.push_back(path);
        return;
    }

    for( int i = 0; i < a.size(); ++i)
    {
        path.push_back(a[i]);
        DFS(a.substr(i+1), b);
        path.pop_back();
    }

    for( int i = 0; i < b.size(); ++i)
    {
        path.push_back(b[i]);
        DFS(a, b.substr(i+1));
        path.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    string a("ABCD"), b("EFGH");
    total = a.size() + b.size();
	DFS(a , b);
    cout << "total count:" << res.size() << endl;
	return 0;
}

/* 
        //for debug
        for( int i = 0; i < path.size(); ++i)
        {
            std::cout<< path[i]  << ",";
        }
 */