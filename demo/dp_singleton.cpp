#include <iostream>
using namespace std;

//Scott Meyer在《Effective C++》item 4
//Scott Meyer在《Effective C++》中提到的 单例模式
//单实例，参见:dp_creational.doc
/*
1. 如果要通过该实例返回的是指针而不是引用:
		static CSingleton * getInstance()
		{
			static CSingleton instance;//局部静态变量
			return &instance;
		}
2. 考虑Singleton 可以继承时，需要将构造函数等声明为 protected
*/

class Singleton
{
	public:
		static Singleton &getInstance()
		{
			//lock(); 					//为了线程安全，c++11不需要
			static Singleton instance;
			//unlock(); 				//c++11不需要
			return instance;
		}
	private:
		Singleton(){}							//必须这样实现,不然上面static Singleton instance; 就会出错
		~Singleton(){}							//必须这样实现
		Singleton(const Singleton &);			//不需要实现
		Singleton &operator=(const Singleton &);//不需要实现

	public:
		int member;		//可选的。 这里只是为了演示，添加了一个成员
};


int main()
{
	Singleton &obj1 = Singleton::getInstance();	//这里不可以是Singleton obj1 = ,因为copy构造函数为私有
	Singleton &obj2 = Singleton::getInstance();

	if(&obj1 == &obj2)	//判断两个对象的地址，因为没有定义对象的==操作符，无法直接判断obj1和obj2相等
		cout << "same!" << endl;

	obj1.member = 1;
	cout << obj2.member << endl;

	return 0;
}



//懒汉式，直到用到时，才实例化
#if defined SINGLETON_LANHAN
//最好使用模版
class Singleton
{
	public:
		static Singleton* getInstance()
		{
//			lock();			//多线程下
			if(!instance)
				instance = new Singleton();
//			unlock();		//多线程下
			
			return instance;
		}
	private:
		static Singleton *instance = NULL;
		Singleton(){}
		~Singleton(){}
		Singleton(Singleton &);
		Singleton & operator=(Singleton &);
};
#endif

#if defined SINGLETON_TEMPLATE
template <class T>
class Singleton
{
	public:
		static inline T& getInstance()
		{
			static T instance;
			return instance;
		}
	private:
		Singleton(){}
		Singleton(const Singleton<T>& );
		Singleton<T>& operator=(const Singleton<T>& );
		~Singleton(){}
		
};
#endif




