/*
����:
$ g++ test_exe_size.cpp -O0; ls -l
$ g++ test_exe_size.cpp -O0 -o main.o; ls -l
$ g++ test_exe_size.cpp -S; ls -l a.exe

$ objdump -SD main.o > ../../1.txt

*/

#include <iostream>
using namespace std;

class A //����ֻ����A��������A�Ķ���ռ�ÿռ䡣
{
	public:
		A(){}
		int a;	//��ռexe�Ŀռ�
		static int s;//����ֻ����������ռexe�Ŀռ�
};

int A::s = 1; //data�Σ�ռ��exe�ռ�
int gi = 2;   //data�Σ�ռ��exe�ռ�

int gbss[100];	//���������С��1-->100�����ı�exe�ռ�
int gbss2;		//ÿ��������һ��bss���ı���,exe�ռ䶼������

//ע�Ͳ�������exe�ռ�
//�����ǲ�����ע��
int main()
{	

	static double b = 3;	//data��,ռ��exe�ռ�
	char c[1] = {0};		//ջ��ռexe�ռ�!!!!!������
	int bb = 2;
	int aa = 5;
	int cc = 9;
	int h = 34653456;	
	int j = 23452345;
	int k = 234634753;	
	int l = 234523423;	
/*
��Щ�����ڻ���ļ� .s ����objdump -SD main.o�ж��ܿ�����Ӧ��Դ���룬	
������ÿ��Ӷ��б����Ż����ӣ�main.o �� a.exe��С��ͬ��һ������
��ע�⡿����ʱ�ǵ��� -oѡ��۲��ļ����������ǲ�������
*/

//	int m = 235464356;
//	int n = 23452345;	
	
	int e = 9;	

	int *p = NULL;
	int *pp = new int[100]; //�ѣ���ռexe�ռ�
	p = new int[100];	//�����С��1-->100�����ı�exe�ռ�

	bb = aa + bb;
	swap(aa, bb);
	cout << bb << endl;	//ÿһ�д��붼ռ�ÿռ�
	
	return 0;
}


