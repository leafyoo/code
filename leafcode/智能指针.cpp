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
using namespace std;


#include <stdlib.h>
#include <time.h>
  

//MS p281
template <typename T>
class SmartPtr
{
	public:
		SmartPtr(T *ptr)
		{
			ref = ptr;
			ref_count = new unsigned int();
			ref_count = 1;
		}

	private:
		int *ref;
		int ref_count;
};



int main()
{

	return 0;
}
