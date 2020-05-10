#include <iostream>
using namespace std;

//MS金典 MP65 中说:单例，工厂
//简单工厂模式，实现四则运算
//BTDP P30
class Operation
{
	public:
		Operation(double n1, double n2):numA(n1),numB(n2)
		{}
		virtual double getRes() const{return 0;}		//若不加 "const = 0;"，则报错:对‘vtable for Operation’未定义的引用
	protected:
		double numA = 0;
		double numB = 0;
};
class OperationAdd:public Operation
{
	public:
		OperationAdd(double n1, double n2):Operation(n1, n2)
		{}
		double getRes() const
		{
			return numA + numB;
		}
};
class OperationSub: public Operation
{
	public:
		OperationSub(double n1, double n2):Operation(n1, n2)
		{}		
		double getRes() const
		{
			return numA - numB;
		}
};
class OperationFactory
{
	public:
		static Operation* createOperate(double n1, double n2, char s)
		{
			switch(s)			//不可以是字符串，如: "+"
			{
				case '+':
					return new OperationAdd(n1, n2);
					break;
				case '-':
					return new OperationSub(n1, n2);
					break;
			}
			return NULL;
		}
};

//简单工厂模式，实现超市收费系统
//BTDP P43

int main()
{
	Operation *oper = OperationFactory::createOperate(2, 1, '+');
	cout << (*oper).getRes() ;
	return 0;
}




