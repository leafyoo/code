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
#include "mylib.hpp"
using namespace std;


#include <stdlib.h>
#include <time.h>


//ms p274, 用C++实现，打印输入文件的最后K行
//循环数组L
#include <fstream>
void saveLatestNifstream(const char *filename)
{
	if(!filename)
		return;
	const int N = 10;
	ifstream file(filename);
	string L[N];
	int size = 0;
	while(file.good())
	{
		getline(file, L[size % N]);
		++size;
	}
	int start = size > N ? (size%N) : 0;
	int count = min(N, size);

	for(int i = 0; i < count; ++i)
		cout << L[(start + i) % N] << endl;
}
void _test_saveLatestNifstream()
{
	saveLatestNifstream("mylib.h");
}



int main()
{

	return 0;
}
