#include <iostream>
#include <list>
using namespace std;

//容器对于构造函数的依赖  C++P P279
#include <vector>
#include <algorithm>
bool isLower(const string &s1, const string &s2)
{
	return s1 < s2;
}	

void string_basic_test()
{
	string s("haha");
	char str[] = "hello!!!!";
	string s1(str+3, 3);	//"lo!"
	
	string::iterator it = s.begin(); 
	string::iterator it1 = find(s.begin(), s.end(), ',');
	
//	s.insert(it, "hah");	//错误：从类型‘const char*’到类型‘char’的转换无效
	s.insert(it, 'a');	
	
	string::iterator beg, end; 
	s.insert(it, beg, end);
	2.3*5
	s.erase(it);
	int len = 2;
	s.erase(s.size() - 2, len);
	s.erase(beg, end);
	
	int index = 2;
	s.substr(index);			//返回从下标index到之后的子串
	s.substr(index, len);		//返回从下标index到之后的5的字符
	s.append("def");			//多种参数样式,见p294

	s.replace(beg, end, "gaga");			//将前两个范围之间用"gaga"替换
	s.replace(beg, end, "gaga", "haha");	//用"haha" 替换 "gaga"
	s.replace(index, len, str);
	
	
    reverse(s.begin(),s.end());



//	s.sort(beg, end, isLower);	//错误：‘std::string’没有名为‘sort’的成员
	sort(s.begin(), s.end());
	s.find('h'); 
	s.find("ha"); 
	s.find('h', index); 	//第一次出现的位置，返回string::size_type类型的下标,或string::npos,
	s.find("ha", index);
	char *ptr = str;
	s.find(ptr, index);
	string s2("animal");
	string::size_type pos = s2.rfind("an"); //pos = 0
	string::size_type pos1 = s2.rfind("An"); //pos = npos，即无

	s.find_first_of("abd");					//查找s中第一个出现在"abc"之中的任意一个字符	
	s.find_first_not_of("abd");					//查找s中第一个出现在"abc"之中的任意一个字符	
	s.find_last_of("abd");	
	s.find_last_not_of("abd");

	//比较,  正数:s > s1,    0:s == s1
	s.compare(s1);
	s.compare(index, len, s1);//s从下标index开始的len个和s2比较

	string s3;
	string s4("haha");
	string s5(s2);
	string s6(10, 'a');

	s[2];
	isalnum(s[2]);
	isalpha(s[2]);
	isdigit(s[2]);
	isupper(s[2]);
	islower(s[2]);
	isspace(s[2]);
	toupper(s[2]);
	tolower(s[2]);


	//https://www.jianshu.com/p/7b0e25d6c2c8
	string str1  = "hello";

	cout << str1[1] << endl;//获取下标为1的字符，e
    cout << str1.at(2) << endl;//获取下标为2的字符，l

    cout << str1.data() << endl;//返回指向字符串首字符的指针，C++11前不一定是以空字符终止的，C++11后是空字符终止的
    cout << str1.c_str() << endl;//返回指向字符串首字符的指针(空字符终止的)

    cout << str1.substr(1,2) << endl;//返回从下标1开始的2个字符，el,参数1默认值为0，参数2默认值为size()-第一个参数值
    cout << str1.substr() << endl;//hello
    cout << str1.substr(3) << endl;//lo

    cout << str1.size()<< endl;//5,size()和length()无区别，都返回字符数量
    cout << str1.length() << endl;//5
    cout << boolalpha << str1.empty() << endl;//判断字符串是否为空


    string str2(" world");
    auto str3 = str1 + str2;//连接两个string，hello world
    auto str4 = str1 + " xiao ming";//连接string和字符指针，hello xiao ming
    str3.assign("12345678");//赋值为12345678

    str3.clear();//清空所有字符

    str3.append("222");//追加字符串
    str3.insert(1, "abc",3);

    cout << str3<<endl;//2abc22

    str3.replace(1, 3,"defg");
    cout << str3 << endl;//2defg22
    str3.erase(1, 4);
    cout << str3 << endl;//222



	//转换整型或浮点数为string
	auto str1 = to_string(123456);
    auto str2 = to_wstring(3.15);


	//转换string为整型
    //转换字符串为有符号整型
    int value1 = stoi("-45");
    long value2 = stol("3.14159");
    long long value3 = stoll("+31337 with words");

    //转换字符串为无符号整型
    //unsigned long value4 = stoul("200000000000000000000000000");// std::out_of_range异常
    //unsigned long long value5 = stoull("words and 2");//std::invalid_argument异常

    cout << value1 << endl;//-45
    cout << value2 << endl;//3
    cout << value3 << endl;//31337

	cout << stoi("20", nullptr, 16) << endl;//32
    cout << stoi("0x20", nullptr, 16) << endl;//32
    cout << stoi("0X20", nullptr, 0) << endl;//32
    cout << stoi("20", nullptr, 8) << endl;//16
    cout << stoi("020", nullptr, 8) << endl;//16
    cout << stoi("020", nullptr, 0) << endl;//16
    cout << stoi("20", nullptr, 36) << endl;//72
    //cout << stoi("20", nullptr, 37) << endl;//异常

    float value1 = stof("3.14");
    double value2 = stod("0.002");
    long double value3 = stold("222");

    auto value4 = stod("INFINITY");//无穷大
    auto value5 = stod("-INF");//负无穷大
    auto value6 = stod("NAN");//非数（NaN）表达式
    auto value7 = stod("-NAN");//非数（NaN）表达式

}


void vec_basic_test()
{
//	vector<string> v("haha"); //错误：从类型‘const char*’到类型‘std::vect
	//因为vec本身是一个数组，怎么可以定义数组而只给第一个值赋值

	vector<int> a(10) ;                            //声明一个初始大小为10的向量
	vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量

	vector<vector<int> > obj(5); //定义二维动态数组大小5行 
    vector<vector<int> > obj(5, vector<int>(6)); //定义二维动态数组5行6列 
	vector<vector<int> > dp(m, vector<int>(n, 0));  //二维数组中所有元素均初始化为0

	vector<int> b(a) ;                             //声明并用向量a初始化向量b
	vector<int> b(a.begin(), a还可以直接使用数组来初始化向量:

	//STL 算法求最值
	cout<<*min_element(v.begin(),v.end())<<endl;//最小元素
	cout<<*max_element(v.begin(),v.end())<<endl;//最大元素

	bool cmp(int a,int b)
	{
		return a<b;
	}
	int num[]={2,3,1,6,4,5};
	cout<<"最小值是 "<<*min_element(num,num+6)<<endl;
	cout<<"最大值是 "<<*max_element(num,num+6)<<endl;
	cout<<"最小值是 "<<*min_element(num,num+6,cmp)<<endl;
	cout<<"最大值是 "<<*max_element(num,num+6,cmp)<<endl;

	sort(coins.begin(), coins.end(), less<int>() 	);	//升序, 注意，不要漏了 ()
	sort(coins.begin(), coins.end(), greater<int>()  );	//降序, 注意，不要漏了 ()

	int n[] = {1, 2, 3, 4, 5} ;
	vector<int> a(n, n+5) ;              //将数组n的前5个元素作为向量a的初值
	vector<int> a(&n[1], &n[4]) ;        //将n[1] - n[4]范围内的元素作为向量a的初值.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值

	vector<string> v(10);
	vector<string> v1;		//空容器vector
	vector<string> v2(v1);
	vector<string> v3(10, "aha");
	vector<string> v4(10);	//10个成员，每个都是空字符串
	vector<int> v5(10, 2);

	v.push_back("ok");
	
	v.empty();
	v.size();//元素个数
	v.max_size(); 
	v.capacity();//vector容器自动调整capacity,用户不必管。

	v.reserve(50);	//当然也可以手动调整capacity为50
	v.resize(5, "haha");
	
	for(vector<int>::size_type ix = 0; ix != v5.size(); ++ix)
	{
		v5.push_back(ix);
	}

	for(vector<int>::size_type ix = 0; ix != v5.size(); ++ix)
	{
		v5[ix] = 0;
	}

	for(vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
	{
		*it = 0;
	}


	//迭代器,也可以用于指针
	vector <int> vec(5, 2);
	vector <int>::const_iterator beg;
	vector <int>::const_iterator end;
	vector <int>::iterator mid = vec.begin() + vec.size()/2;//中点

	list<int> lst(vec.begin(), vec.end());//类型可不相同
	//由于list不是顺序存储，list容器不支持算术运算、关系运算，即不可以:lst.begin()+ ...

	//逆序迭代器
	vec.rbegin();//指向最后一个元素 
	vec.rend();//指向第一个元素前面的位置

	sort(vec.begin(), vec.end());  
	sort(vec.rbegin(), vec.rend());  //逆序排序

	// reverse iterator of vector from back to front  
	vector<int>::reverse_iterator rit;  
	for (rit = vec.rbegin(); rit != vec.rend();++rit)	//这里要向it赋值，则it要定义为reverse_iterator类型
	    cout << *rit << endl; // prints 9,8,7,...0  


	vec.at(11);//若n越界则抛出异常

	vec.push_back(6);//vector只支持尾插
	vec.insert(vec.end(), 10, 6);
	vec.insert(vec.end(), beg, end);
	vec.insert(vec.begin(), beg, end);	//不可以push_front，但是可以insert

	vec.erase(mid);	//不可以pop_front,但是可以erase()
	//错，不支持:vec.push_front("a");

	vec.~vector<int>(); //用析构函数清楚vec及其内存
}

void vec_erase_test()
{
	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
 	v.push_back(3);
	v.push_back(4);   
	v.push_back(5);
	v.push_back(6);

	vector<int>::iterator it = v.begin();
	for(it = v.begin();it != v.end(); ++it)
		cout << *it << endl;    
    
    cout << endl; 

    v.erase(v.begin() + 3, v.end());

	for(it = v.begin();it != v.end(); ++it)
		cout << *it << endl;      
}

void vec_of_class_test()
{
	class C
	{
		public:
			//C(){}
			C(int a):a(a){}
			~C(){}
		private:
			int a;
	};	

	vector<C> empty;
	//vector<C> bad(10);//错误：对‘vec_of_class_test()::C::C()’的调用没有匹配的函数
	vector<C> ok(10,1);

}

#include <algorithm>
void vec_iterator()
{
	int arr[] = {1, 4, 2, 3};
	vector<int> v;
	v.assign(arr, arr+4);

	vector<int>::iterator it = v.begin();

	stable_sort(v.begin(), v.end());
	for(it = v.begin();it != v.end(); ++it)
		cout << *it << endl;

	cout << "reverse_iterator:" << endl;
	vector<int>::reverse_iterator rit;	//想要用rbegin，则必须用reverse_iterator来定义
	for(rit = v.rbegin();rit != v.rend(); ++rit)
		cout << *rit << endl;
	
	cout << "reverse:" << endl;
	for(it = v.begin();it != v.end(); ++it)
		cout << *it << endl;
}


void vec_swap()
{
	vector<int> v1;
	v1.reserve(110);
	v1.push_back(100);
	v1.push_back(101);
	
	cout << v1.capacity() << endl;
	
	v1.erase(v1.begin(), v1.end());
	cout << v1.capacity() << endl;
	
	vector<int>().swap(v1);		
	cout << v1.capacity() << endl;
}
/*
110
110
0
*/


void list_basic_test()
{
	list<int> l;
	list<string> lst;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	list<int>::iterator it = l.begin();

	std::cout << *it << std::endl;
//	it = it+1;						//no match for ‘operator+’ 				
	++it;							//这样可以!!
	std::cout << *it << std::endl;

	list<string>::iterator it1 = lst.begin();
	lst.insert(it1, string("dog"));   				//在iter之前插入"dog"
	lst.insert(it1, 5, "dog"); 					//在iter之前插入5个"dog"
	lst.insert(it1, lst.begin(), lst.end()); 	//在iter之前插入一段
	lst.sort();									//有自己单独的sort
	lst.unique();					//与算法的unique不同:这里删除了重复
	lst.empty();					//判断空
	lst.resize(5);					//多则删，少则加
}


#include <set>
void set_basic()
{
	set<string> s;
	s.insert("a");
	set<string>::iterator s_it = s.find("a");
	s.find("c"); //return iterator of 1
	s.count("c"); //1的个数

	

		
}



#include <map>
void map_basic_test()
{
	map<string, int> m;
	std::cout << m["shenzhen"] << std::endl;	//访问不存在的元素，导致添加键
	std::cout << m.count("shenzhen") << std::endl;	//

	map<char, char> parMap{
				{'{', '}'},
				{'[', ']'},
				{'(', ')'},
			};//知识点:map初始化方法
}
/*
0 	//int，所以被初始化为0
1	//此键存在
*/


//嵌套map
void map_in_map()
{
      map<int,map<int,string> >multiMap; //对于这样的map嵌套定义，有两种插入方法：
      map<int, string> temp;  //定义一个map<int, string>变量，对其定义后在插入multiMap

      temp.insert(make_pair(90,"hi"));
      temp.insert(pair<int,string>(100,"maxi")); //pair<int,string>()和make_pair()有相同作用

      multiMap.insert(make_pair(10, temp));   //将临时变量插入到multiMap中

      multiMap[10][80]="xiaoyu"; //可以直接赋值
      mulitMap[5][30]="xiaop";


      map<int,map<int,string> >::iterator multitr;  // 以下是如何遍历本multiMap
      map<int,string>::iterator intertr;
      for(multitr=multiMap.begin();multitr!=multiMap.end();multitr++)
      {
           for(intertr= multitr ->second.begin(); intertr != multitr ->second.end(); intertr ++)
            std::cout<< multitr ->first<<" "<<intertr->first<<" ("<< intertr -> second <<")"<<endl;
      }

      return 0;
   
}


void map_test()
{
	map<int , string> m;
	
	m.insert(make_pair(11, "aa"));
	m.insert(make_pair(22, "bb"));
	m.insert(make_pair(33, "cc"));

	pair<int, string> p(44, "dd");
	
	m.insert(p);//有则不动,不能覆盖，无则加入
	m.insert(make_pair(55, "ee"));
	m.insert(map<int, string>::value_type(66, "ff"));

	map<int, string> word_count;
	pair<map<string, int>::iterator, bool> ret 
		= word_count.insert(make_pair("book", 3));
	if(!ret->second)
		++ret.first->second;

	//另一种插入方式
	m[44] = "dd";	//可以，覆盖之前的value

	cout << "aa:"<< m[11] << endl;
	//改变value
	m[11] = "AA";	
	cout << m[11] << endl;
	m.insert(make_pair(11, "BB"));
	cout << m[11] << endl;

	//size
	cout << "m.size() :"<< m.size() << endl;

	//遍历打印
	map<int, string>::iterator it = m.begin();
	for(it = m.begin();it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;	
	}

	//查找key
	it = m.find(11);
	if(it != m.end())
		cout << "Found 11" << endl; 
	else
		cout << "No 11" << endl;

	//查找value，并删除
	for(it = m.begin(); it != m.end(); ++it)
	{
		if(it->second == "bb")
		{
			cout << endl;
			cout << "del:" << it->first << endl;
			m.erase(it->first );
		}
	}

	//打印删除后的map
	for(it = m.begin();it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;	
	}

	m.erase(m.begin(), m.end());
	cout << "erase all:" << endl;
	//打印删除后的map
	for(it = m.begin();it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;	
	}

	multimap<string, int> mu;	//multimap允许一个键多次出现
	
}
/*
通过[]操作不仅仅是插入键值对，我们也可以通过键key检索出映射值mapped value。
而且我们利用[]操作可以轻松地统计信息，如有这样这样一些键值对：
(book1,1)、(book2,2)、(book1,2)、(book3,1)、(book3,5)
我们计算每种book的数量总和。我们可以这样做：将它们读入一个map<string,int>：
*/
void map_show_total_num_test()
{
	map<string, int> m;
	int num;
	string book;
	int i = 3;
	while(i && cin >> book >> num )
	{
		--i;
		m[book] += num;
	}
		
	map<string, int>::iterator it = m.begin();
	for(; it != m.end();++it)
		cout << it->first << " " << it->second << endl;
	
}


#include <stack>
void stack_basic()
{
	stack<int> stk;
	stack<string, vector<string>> sv;
	
			stk.push(44);
			stk.push(55);
	cout << stk.empty();
	cout << stk.size();
	cout << stk.top();
			stk.pop();
	
}
//0255


#include <queue>
void queue_basic()
{
	queue<int> q;
			q.push(11);
			q.push(12);
			q.push(13);
	cout<<	q.empty();
	cout<<	q.size();
			q.pop();
	cout<<	q.front();
	cout<<	q.back();//获取尾元素
}
//031213


void pair_basic()
{
	//pair不是容器，是一种标准类型
	pair<string, string> p;
	pair<string, string> city("shenzhen", "guangdong");
	pair<string, vector<int> > line;
	
	if(city.first == "shenzhen" && city.second == "guangdong")
		cout << "yes" << endl;
	
	city = make_pair("sz", "gd");//与下面等效
	city = pair<string, string>("sz", "gd");

}


void print(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
	for(; beg != end; ++beg)
	{
		cout << *beg ;
		if(beg != end)
			cout << " ";
	}
}

bool findVec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
	while(beg != end)
	{
		if(*beg == val)
			return true;
		else
			++beg;
	}
	return false;
}


#include <algorithm>
void alg_basic()
{
	list<int> l(10, 3);
	int arr[] = {1,2,3,4,5};
	vector<int> vec(arr, arr+3);
	vector<int> v1, v2;
	v1.assign(l.begin(), l.end());
	v2.assign(10, 3);
	v1 = v2;
	v1.swap(v2); 		//swap不会使容器迭代器失效

	int n;
	int start = 100;
	n = accumulate(vec.begin(), vec.end(), start);//start是初始累加值
	cout << n << endl;
	vector<string> v3(10, "a");
	string newstr;
	newstr = accumulate(vec.begin(), vec.end(), "");//将所有字符串连接起来

	vector<int> vTarget, vMatch;
	vTarget.assign(arr, arr+4);
	vMatch.assign(arr+2, arr+4);

	vector<int>::iterator it;
	it = find_first_of(vTarget.begin(),vTarget.end(),vMatch.begin(),vMatch.end());
	cout << *it << endl;

	sort(vec.begin(), vec.end());
	for(it = vec.begin(); it != vec.end(); ++it)
		cout << *it << endl;

	fill(vec.begin(), vec.end(), 2);//重置所有元素为2
	cout << "fill" << endl;
	
	for(it = vec.begin(); it != vec.end(); ++it)
		cout << *it << endl;

	//Aborted (核心已转储)
//	fill_n(vec.begin(), 10, 2);		//填充10个2
//	cout << "fill_n" << endl;
//	for(it = vec.begin(); it != vec.end(); ++it)
//		cout << *it << endl;


	fill_n(back_inserter(vec), 10, 2);		//在末尾填充10个2，相当于vector的push_back

	list<int> lst, lst2;
	int arr1[] = {1,2,3}; 
	lst.assign(arr1, arr1+3);	//注意后面是开区间!!
	//插入迭代器，设lst:1 2 3
	copy(lst.begin(), lst.end(), front_inserter(lst2)); //lst2: 3 2 1
//	copy(lst.begin(), lst.end(), back_inserter(lst2)); //lst2: 1 2 3

	list<int>::iterator itl = lst2.begin();
	for(; itl != lst2.end(); ++itl)
		cout << *itl <<endl;

	reverse(lst2.begin(), lst2.end());
	for(itl = lst2.begin(); itl != lst2.end(); ++itl)
		cout << *itl <<endl;

}

int main()
{
//	list_basic_test();
//	vec_swap();
//	stack_basic();
//	queue_basic();
//	pair_basic();
//	alg_basic();

    vec_erase_test();

	return 0;
}




