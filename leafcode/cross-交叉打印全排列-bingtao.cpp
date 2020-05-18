#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::vector<string> result;

void calc(std::vector<char> &v1, std::vector<char> &v2, std::vector<char> path)
{
	if (!v1.size() && !v2.size())
	{
		//path complete
		string str = "";
		for (int i = 0; i < path.size(); i++)
		{
			str += path[i];
		}
		cout << str << endl;
		result.push_back(str);
		return;
	}
	if (v1.size())
	{
		//chose v1
		char a = v1.back();
		if (find(path.begin(), path.end(), a) == path.end())
		{
			path.push_back(a);
			v1.pop_back();
			calc(v1, v2, path);
			v1.push_back(a);
			path.pop_back();
		}
	}
	if (v2.size())
	{
		//chose v2
		char a = v2.back();
		if (find(path.begin(), path.end(), a) == path.end())
		{
			path.push_back(a);
			v2.pop_back();
			calc(v1, v2, path);
			v2.push_back(a);
			path.pop_back();
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	std::vector<char> v1;
	std::vector<char> v2;
	v1.push_back('D');
	v1.push_back('C');
	v1.push_back('B');
	v1.push_back('A');
	//v2
	v2.push_back('H');
	v2.push_back('G');
	v2.push_back('F');
	v2.push_back('E');
	std::vector<char> path;
	calc(v1, v2, path);
	return 0;
}