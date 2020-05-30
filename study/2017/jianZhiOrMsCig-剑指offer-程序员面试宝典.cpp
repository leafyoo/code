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




//jor p67, 在list末尾添加节点
void addToTail(Node **pHead, int val)
{
	if(!pHead)
		return;
	Node *tmp = new Node;
	tmp->val = val;
	tmp->next = NULL;
	if(!(*pHead))
	{
		*pHead = tmp;
	}
	else
	{
		Node *p = *pHead;
		for(; p->next != NULL; p = p->next)
		{
			;
		}
		p->next = tmp;
	}
}











#define __CIG__






void _test_addToTail()
{
	Node *h = new Node();
	h->val = 2;
	h->next = NULL;
	
//	Node **ph = &h;
//	addToTail(ph, 1);
//	cout << (*ph)->val << endl;
//	cout << (*ph)->next->val << endl;

	Node *nh = NULL;
	Node **ph = &nh;
	addToTail(ph, 1);
	cout << (*ph)->val << endl;
	
}




//jor p73, 由前序、中序遍历结果重建二叉树
TreeNode *doCreateTree(int *pre, int *preEnd, int *in, int *inEnd)
{
	int rootVal = pre[0];
	TreeNode *root = new TreeNode();
	root->val = rootVal;
	root->left = root->right = NULL;
	if(pre == preEnd)
	{
		if(in == inEnd)
			return root;
		else
			throw exception();
	}

	//在中序遍历中找根节点的值
	int *rootIn = in;
	while(rootIn <= inEnd && *rootIn != rootVal)
		++rootIn;
	if(rootIn == inEnd && *rootIn != rootVal)
		throw exception();

	int leftLen = rootIn - in;
	int *leftPreEnd = pre + leftLen;
	if(leftLen > 0)
	{
		root->left = doCreateTree(pre+1, leftPreEnd,in,rootIn-1);
	}
	if(leftLen < preEnd - pre)
	{
		root->right = doCreateTree(leftPreEnd+1,preEnd, rootIn+1,inEnd);
	}
	return root;
}
TreeNode *createTree(int *pre, int *in, int len)
{
	if(!pre || !in || len < 1)
		return NULL;
	return doCreateTree(pre, pre+len, in, in+len);
}

//jor p 76 , 两个栈实现队列
template <typename T> class cQ
{
	public:
		cQ(){}
		~cQ(){}
		void addTail(const T& node);
		T delHead();
	private:
		stack<T> st1;
		stack<T> st2;
};

template <typename T>
void cQ<T>::addTail(const T& node)	
{
	st1.push(node);
}

template <typename T>
T cQ<T>::delHead()
{
	if(st2.size()<=0)
	{
		while(st1.size() > 0)
		{
			st2.push(st1.top());
			st1.pop();
		}
	}
	if(st2.size() == 0)
		throw exception();
 	T tmp = st2.top();
	st2.pop();

	return tmp;
}

//jor p83, 求旋转数组中的最小值, exp: 34512
int minInRotate(int *a, int len)
{
	if(!a || len < 0)
		throw exception();				//错误:throw exception("invalid");
	int beg = 0;
	int end = len - 1;
	int m = 0;
	while(a[beg] >= a[end])
	{
		if(end - beg == 1)
		{
			m = end;
			break;
		}
		m = (beg + end)/2;
		if(a[beg] == a[end] && a[m] == a[beg])
		{
			int min = a[beg];
			while(beg <= end)	//逐一往后遍历比较
			{
				if(a[beg] < min)
					min = a[beg];
				++beg;
			}
			return min;
		}

		if(a[beg] <= a[m])
			beg = m;
		else if(a[m] >= a[end])			//执行上面后，这里不执行
			end = m;
	}
	return a[m];
}

void _test_minInRotate()
{
	int a[] = {1,1,1,0,1};
	cout << minInRotate(a, 5);
}

int fabonacci_1(int n)
{
	if(n < 1)
		return 0;
	if(n < 2)
		return 1;
	
	int f0 = 0;
	int f1 = 1;
	int fn = 0;
	for(int i = 2; i <= n; ++i)
	{
		fn = f0 + f1;
		f0 = f1;
		f1 = fn;
	}
	return fn;
}

void _test_fabonacci_1()
{
	cout << fabonacci_1(3);
}



//jor p116, O1时间内删除链表的一个节点
//*********************     删节点    ***********************
/*
假设现有一个单向的链表，但是只知道只有一个指向该节点的指针p，
并且假设这个节点不是尾节点，试编程实现删除此节点

比如链表是：1 2 3 4 5

方法2，效率会更高点：
 把3（值域）复制到2，变成1 3 3 4 5 然后修改原来2 结点的尾指针指向4 然后删除第二个3

1 3 [3] 4 5
*/
void rmNodeO1(Node **pHead, Node *pn)
{
	if(!pHead || !(*pHead) || !pn)
		return;
	if(pn == *pHead)				//pn是头:1个；多个
	{
		(*pHead) = pn->next;		//包含了两种情况:即1个节点的情况
		delete pn;
		pn = NULL;
		return;
	}	
	if(pn->next == NULL)			//pn是尾
	{
		Node *pre;
		for(pre = *pHead; pre->next != pn; pre = pre->next)
		{
			;
		}
		delete pn;
		pn = NULL;
		pre->next = NULL;
		return;
	}

	Node *tmp = pn->next;
	pn->val = pn->next->val;
	pn->next = pn->next->next;
	delete tmp;
	tmp = NULL;

}
void _test_rmNodeO1()
{   
	Node *h = new Node();

	h->val = 1;
	h->next = new Node();
	
	h->next->val = 2;
	h->next->next = NULL;
	
//	Node **ph = &h;
//	rmNodeO1(ph, h);

//	Node **ph = &(h->next);	//一个节点
//	rmNodeO1(ph, h->next);

	Node **ph = &h;			//尾节点
	rmNodeO1(ph, h->next);

	cout << (*ph)->val << endl;	
	cout << (*ph)->next->val << endl;	
}   

//jor p134, 判断是否为子树
bool doIsSubTree(TreeNode *r1, TreeNode *r2)
{
	if(!r1)
		return false;
	if(!r2)
		return true;
	if(r1->val != r2->val)
		return false;
	return doIsSubTree(r1->left, r2->left) && 
		doIsSubTree(r1->right, r2->right);
}
bool isSubTree(TreeNode *r1, TreeNode *r2)
{
	if(!r1 || !r2)
		return false;
	
	bool res = false;
	if(r1->val == r2->val)
		res = doIsSubTree(r1, r2);
	if(!res)
		res = isSubTree(r1->left, r2);
	if(!res)
		res = isSubTree(r1->right, r2);
	
	return res;
}

//jor p142, 将一个二叉树镜像
void mirrorNewTree(TreeNode *root)
{
	if(!root)
		return;

	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	
	if(root->left)
		mirrorNewTree(root->left);
	if(root->right)
		mirrorNewTree(root->right);
}

//jor p149, 实现一个栈，使得min，push，pop操作时间复杂度都是O1
template <typename T>
class minStack
{
	public:
		minStack(){}
		~minStack(){}
		void push(T val)
		{
			st1.push(val);
			if(!st2.empty() && val > st2.top())
				st2.push(min());					//错:st2.push(st2.top);
			else
				st2.push(val);
		}
		void pop()
		{
			if(st1.empty() || st2.empty() )
				throw exception();
			st1.pop();
			st2.pop();
		}
		const T& min() const
		{
			if(st2.empty())
				throw exception();
			return st2.top();			
		}
	private:
		stack<T> st1; 
		stack<T> st2;
};
void _test_minStack()
{
	minStack<int> c;
	c.push(2);
	c.push(3);
	c.push(1);
	c.push(0);
	c.pop();
	cout << c.min();
}

//jor p184，找出最小的k个数
void getLeastNumbers(vector<int> &v, multiset<int, greater<int>> &s, size_t k)
{
	if(k < 1 || v.size() < k)
		return;
	
	s.clear();
	vector<int>::const_iterator it = v.begin();
	for(; it != v.end(); ++it)
	{
		if(s.size() < k)
			s.insert(*it);
		else
		{
			if(*it < *(s.begin()))				//*(s.begin())
			{
				s.erase(s.begin());				//必须先删除腾位置
				s.insert(*it);
			}
		}
	}
}

//jor p188，最大子数组求和，数组里有正有负，求连续的一个或多个组成一串使和最大，时间复杂度On
bool gError = false;
int maxSumOfSubArr(int *a, int n)
{
	if(!a || n < 1)
	{
		gError = true;
		return 0;
	}

	gError = false;
	int maxSum = a[0], sum;
	for(int i = 0; i < n; ++i)
	{
		sum = 0;
		for(int j = i; j < n; ++j)		//j也从i开始记,因为数组长度可以是1 !!!!!!
		{
			sum += a[j];
			if(maxSum < sum)
				maxSum = sum;
		}
	}
	return maxSum;
}

int maxSumOfSubArr_2(int *a, int n)
{
	if(!a || n < 1)
	{
		gError = true;
		return 0;
	}

	gError = false;
	int maxSum = 0x80000000;				//int的最小负数
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		if(sum <= 0 )
			sum = a[i];
		else
			sum += a[i];
		if(sum > maxSum)
			maxSum = sum;
	}
	return maxSum;
}

void _test_maxSumOfSubArr()
{
	int a[] = {1};
	cout << maxSumOfSubArr_2(a, sizeof(a)/sizeof(a[0])) << endl;

	int a1[] = {-1, 1};
	cout << maxSumOfSubArr_2(a1, 2) << endl;

	int a2[] = {-1,1,1};		//从第二个开始:2
	cout << maxSumOfSubArr_2(a2, 3) << endl;

	int a3[] = {2,-3, 1};		//会不会只是挑最大的加
	cout << maxSumOfSubArr_2(a3, 2) << endl;

	int a4[] = {-2, -1};		//-1
	cout << maxSumOfSubArr_2(a4, 2) << endl;

}


//jor p210，求2个list的公共node，即第一个交叉点
int getListLen(Node *p)
{
	if(!p)
		return 0;
	int num = 0;
	while(p)
	{
		++num;
		p = p->next;
	}
	return num;
}
Node* firstCommonNode(Node *n1, Node *n2)
{
	if(!n1 || !n2)
		return NULL;
	int len1 = getListLen(n1);
	int len2 = getListLen(n2);

	if(len1 < len2)
	{
		for(int i = 0; i+len1 < len2; ++i)
			n2 = n2->next;
	}
	else
	{
		for(int i = 0; i+len1 < len2; ++i)
			n1 = n1->next;
	}
	for(; n1 && n2; n1 = n1->next, n2 = n2->next)			//是:n1 && n2,不是 ***->next
	{
		if(n1 == n2)
			return n1;
	}
	return NULL;	
}
void _test_firstCommonNode()
{
	Node *h = new Node();
	h->val = 2;
	
	h->next = new Node();
	h->next->val = 3;
	h->next->next = NULL;	

	Node *h2 = new Node();
	h2->val = 4;
	
	h2->next = h;

	Node *res = firstCommonNode(h, h2);
	cout << res->val;
}

//jor p221，数字k在有序数组中
//有序数组才可以二分法
int firstKInSortedArr(int *a, int n, int k)
{
	if(!a || n < 1)
		return -1;
	int m, beg = 0, end = n-1;
	while(beg <= end)						//<=
	{
		m = (beg + end)/2;
		if(a[m] == k)
		{
			if(m > 0)
			{
				if(a[m-1] != k)
					return m;
				else
					end = m - 1;
			}
			else
				return m;
		}
		else if(a[m] < k)
			beg = m + 1;
		else
			end = m - 1;
	}
	return -1;
}
void _tset_firstKInSortedArr()
{
//	int a[] = {0,1,2,2,2,2,3};
//	cout << firstKInSortedArr(a, 7, 2);	
	
//	int a[] = {1};
//	cout << firstKInSortedArr(a, 1, 2);

	int a[] = {1,2,2,2,2,2,2};
	cout << firstKInSortedArr(a, 7, 2);

}

//jor p224，二叉树的深度
int treeDepth_digui(TreeNode *root)
{
	if(!root)
		return 0;
	
	int leftD = treeDepth_digui(root->left);
	int rightD = treeDepth_digui(root->right);
	return leftD > rightD ? (leftD+1) : (rightD + 1);
}
void _test_treeDepth_digui()
{
	int a[] = {1,2,3,4,5};
	cout << treeDepth_digui(arrToBSTTree(a, 5));
}

//jor p226，是否为平衡二叉树。即判据:树中任意节点的左右子树深度差不大于1
bool isBalanceTree_digui(TreeNode *root)
{
	if(!root)
		return true;
	int leftD = treeDepth_digui(root->left);
	int rightD = treeDepth_digui(root->right);
	int diff = leftD - rightD;
	if(diff > 1 || diff < -1)
		return false;
	return isBalanceTree_digui(root->left)
		&& isBalanceTree_digui(root->right);
}

bool isBalanceTree(TreeNode * root, int *depth)
{
	if(!root)
	{
		*depth = 0;		
		return true;
	}

	int left, right;
	if(isBalanceTree(root->left, &left) &&
		isBalanceTree(root->right, &right))
	{
		int diff = left - right;
		if(diff < -1 || diff > 1)
			return false;
		else
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}


//jor p235, 以单词为单位翻转词序
void doReverseStr(char *beg, char *end)
{
	if(!beg || !end || !(*beg) || !(*end))
		return;
	char tmp;
	char *p1 = beg, *p2 = end;
	while(p1 < p2)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;

		++p1;
		--p2;
	}
}
char * reverseStr(char *s)
{
	if(!s || !(*s))
		return NULL;
	int len = strlen(s);
	if(len < 2)
		return s;
	doReverseStr(s, s+len-1);
	char *beg = s, *end = s;									//又特么漏了*
	while(*beg)													//beg
	{
		if(*beg == ' ')
		{
			++beg;
			++end;
		}
		else if(*end == ' ' || *end == '\0')
		{
			doReverseStr(beg, end-1);
			beg = end;
		}
		else
			++end;
	}
	return s;
}
void _test_reverseStr()
{
	const char *s = "he is a geek.";
	char a[20] = {0};
	strcpy(a, s);
	reverseStr((char *)a);
	cout << (char *)a;
}

//jor p246, 约瑟夫环，从有n个节点的环里每次删除第m个结点
int josephuseCircle(int n, int m)
{
	if(n < 1 || m < 1)
	{
		return 0;
		gError = true;
	}
	gError = false;
	list<int> lst;
	for(int i = 0; i < n; ++i)
		lst.push_back(i);
	list<int>::iterator it = lst.begin(), next;
	while(lst.size() > 1)
	{
		for(int i = 1; i < m; ++i)
		{
			++it;
			if(it == lst.end())
				it = lst.begin();
		}
		next = ++it;						//错误:it+1;：no match for ‘operator+’ (
		if(next == lst.end())
			next = lst.begin();
		lst.erase(--it);
		it = next;
	}
	return *it;
}
void _test_josephuseCircle()
{
	
	cout << josephuseCircle(2, 1);
}


/*
将搜索二叉树转换成双向链表
*/



#define __MS_JinDian__

//MS 324，有序数组里
bool findNumbersWithSum(int *a, int len, int sum, int *n1, int *n2)
{
	if(!a || len < 2 || !n1 || !n2)
		return false;
	int beg = 0, end = len-1;
	long long curSum = 0;
	while(beg < end)
	{
		curSum = a[beg] + a[end];
		if(curSum == sum)
		{
			*n1 = beg;
			*n2 = end;
			return true;
		}
		else if(curSum < sum)
			++beg;
		else
			--end;
	}
	return false;
}
void _test_findNumbersWithSum()
{
	int a[] = {1,2,2,3,4,5};
	int n1, n2;
	findNumbersWithSum(a, 6, 5, &n1, &n2);
	cout << n1 << n2;
}



//ms p153，是否为bst(二叉查找树)
bool isBst(TreeNode *root, int min, int max)
{
	if(!root)
		return true;
	if(root->val < min || root->val > max)
		return false;
	if(!isBst(root->left, min, root->val)
		|| !isBst(root->right, root->val, max))
		return false;
	return true;
}
void _test_isBst()
{
	int a[] = {1,2,7,4,5};
	cout << isBst(arrToBSTTree(a, 5), -100, 100);
}

//ms p221, n个台阶，一次可以爬1、2、3个，求上楼多少种方法
int climbStairs123(int n)
{
	if(n < 1)
		return 0;
	if(n < 4)
		return n;
	int f1 = 1, f2 = 2, f3 = 3, fn = 0;
	for(int i = 3; i < n; ++i)
	{
		fn = f1 + f2 + f3;
		f1 = f2;
		f2 = f3;
		f3 = fn;
	}
	return fn;
}
int climbStairs123_digui(int n)
{
	if( n < 1)
		return 0;
	if(n < 4)
		return n;
	return climbStairs123_digui(n - 1) 
		+ climbStairs123_digui(n - 2)
		+ climbStairs123_digui(n - 3);
}

void _test_climbStairs123()
{
	cout << climbStairs123(4) << endl;
	cout << climbStairs123_digui(4) << endl;
}

//ms p260, m x n的矩阵，行、列均按升序排，查找某个元素
bool isNinMatrix(int (*a)[2], int m, int n, int t)	//int a[][]:多维数组‘a’的声明必须至少指定除第一维以外
{
	if(!a || m<1 || n<1)
		return false;
	int i = 0, j = n-1;
	while(i < m && j >= 0)
	{
		if(a[i][j] == t)
			return true;
		else if(a[i][j] < t)
			++i;
		else
			--j;
	}
	return false;
}
void _test_isNinMatrix()
{
	int a[][2] = {{1,2},{3,4}};
	cout << isNinMatrix(a, 2, 2, 1);
}


//ms p282, 分配二维数组，将malloc函数的调用次数降到最少，确保arr[i][j]可访问
int **malloc_2d(int m, int n)
{
	if(m < 1 || n < 1)
		return NULL;
	int head = m * sizeof(int*);
	int data = m * n * sizeof(int);
	int **pp = (int **)malloc(head + data);
	
	int *p = (int *)(pp+m);					//指到数据区域。
	for(int i = 0; i < m; ++i)
	{
		pp[i] = p + i * n; 					//每一个都必须被设置
	}
	
	return pp;
}




//cig p38, 删除中间节点，一个节点则不删；1 2删1；1 2 3删2；1 2 3 4删2
Node* rmMiddleNode(Node *h)
{
	if(!h || !h->next)
		return h;
	if(!h->next->next)
	{
		Node *tmp = h;
		h = h->next;
		delete tmp;
		return h;
	}
		
	
	Node *pre = h, *cur = h->next->next;		//想:如果cur也是h，则下文无法确定pre的前一个节点，所以这里这样定cur的初值。
	while(cur->next && cur->next->next)
	{
		pre = pre->next;
		cur = cur->next->next;
	}
	Node *tmp = pre->next;
	pre->next = pre->next->next;
	delete tmp;
	tmp = NULL;
	return h;
}
void _test_rmMiddleNode()
{
//	int a[] = {1,2,3,4,5};
//	int a[] = {1,2,4,5};
//	int a[] = {1,2,5};
	int a[] = {1,2};
	Node *h = arrToList(a, sizeof(a)/sizeof(a[0]));
	printList(rmMiddleNode(h));
}

//CIG P41，反转单链表
//不可以返回局部变量的引用:Node dum; return &dum;
Node *reverseList(Node *h)				//不必判断空，下文会包含，所以这里省略可以提高性能。
{
	if(!h || !h->next)
		return h;
	Node *pre = NULL, *next = NULL;
	while(h)
	{
		next = h->next;
		h->next = pre;
		pre = h;
		h = next;
	}
	return pre;
}
void _test_reverseList()
{
//	int a[] = {1,2,3,4,5};
//	int a[] = {1,2,4,5};
//	int a[] = {1,2,5};
	int a[] = {1,2};
	Node *h = arrToList(a, sizeof(a)/sizeof(a[0]));
	printList(reverseList(h));
}


//cig p71, 删除无序list中的值重复节点。
#include <set>
Node *rmDumplicateNodeInDisorderedList(Node *h)
{
	if(!h || !h->next)
		return h;
	set<int> set1;
	set1.insert(h->val);
	Node *tmp = NULL;
	while(h->next)
	{
		if(set1.count(h->next->val))
		{
			tmp = h->next;
			h->next = h->next->next;
			delete tmp;
		}
		else
		{
			set1.insert(h->next->val);
			h = h->next;
		}
	}
	return h;
}
void _test_rmDumplicateNodeInDisorderedList()
{
//	int a[] = {1,2,2,5,2};
	int a[] = {1,1};

	Node *h = arrToList(a, sizeof(a)/sizeof(a[0]));
	printList(rmDumplicateNodeInDisorderedList(h));
	
}

//cig p79,单链表的选择排序
Node *getMinNodePre(Node *h)
{
	if(!h )
		return NULL;
	int min = h->val;
	Node *minPre = NULL, *pre = NULL, *cur = h;
	while(cur)
	{
		if(min > cur->val)
		{
			minPre = pre;
			min = cur->val;
		}
		pre = cur;
		cur = cur->next;
	}
	return minPre;
}
Node *selectSortOfList(Node *h)
{
	if(!h || !h->next)
		return h;
	Node dum;
	dum.next = h;
	Node *sortPre = &dum;
	for(;sortPre->next; )
	{
		Node *minPre = getMinNodePre(sortPre->next);
		if(!minPre)
		{
			sortPre = sortPre->next;
		}
		else
		{
			Node *next = minPre->next;
			minPre->next = minPre->next->next;
			next->next = sortPre->next;
			sortPre->next = next;
			sortPre = sortPre->next;
		}
	}
	return dum.next;
}
void _test_selectSortOfList()
{
	int a[] = {9,2,2,5,2,3};
//	int a[] = {3,2};

	Node *h = arrToList(a, sizeof(a)/sizeof(a[0]));
	printList(selectSortOfList(h));	
}

//cig p104,二叉树的序列化(用前序遍历)。序列化:把二叉树记录成文件的过程
string serialTreeByPre(TreeNode *r)
{
	const char *a[] = {"1", "2", "3", "4", "5"};
	if(!r)
		return "#_";
	string res = a[r->val - 1];
	res += "_";
	res += serialTreeByPre(r->left);
	res += serialTreeByPre(r->right);
	
	return res;
}
void _test_serialTreeByPre()
{
	int a[] = {1,2,3,4,5};
//	cout << arrToBSTTree(a, 5)->left->right;
	cout << serialTreeByPre(arrToBSTTree(a, 5-1));

}

//CIG P150，根据中序遍历结果[或有序数组]重建BST
TreeNode *sortArrToBST(int *a, int n)
{
	return arrToBSTTree(a, n);
	
}

//CIG P199，兑换零钱的多少种方法
//用1个index元，2个index元，....所有这些种情况之和，这些情况用循环。
//其中，1个index元又对应:1个index+1元、2个index+1元、，这些情况用递归。
int coinChangeDo(int *a, int n, int index, int price)
{
	int res = 0;
	if(index == n)
		res = (price == 0 ? 1 : 0);					//钱数为0，是一种表示方法:无硬币
	else
	{
		for(int i = 0; a[index] * i <= price; ++i)
		{
			res += coinChangeDo(a, n,index+1, price - a[index] * i);
		}
	}
	return res;
}
int coinChange(int *a, int n, int price)
{
	if(!a || n < 1 || price < 0)
		return 0;
	return coinChangeDo(a, n, 0, price);
}
void _test_coinChange()
{
	int a[] = {1,5,10};
	cout << coinChange(a, 3, 10);
}

//二维数组有问题
int coinChange_dp(int *a, int n, int price)
{
	if(!a || n < 1 || price < 0)	
		return 0;
	int *tmp = new int[n*(price + 1)];
	int **dp = &tmp;
	for(int i = 0; i < n; ++i)
	
	cout << dp [1][0];
	int j = 1;
	for(; j * a[0] <= price ; ++j)
		dp[0][j * a[0]] = 1;
	for(int i = 1; i < n;++i)
	{
		for(j= 1; j <= price; ++j)
		{
			dp[i][j] = dp[i-1][j];
			dp[i][j] += (j-a[i] >= 0) ? dp[i][j-a[i]] : 0;
		}
	}
	return dp[n-1][j];
}
void _test_coinChange_dp()
{
	int a[] = {1,5,10};
	cout << coinChange_dp(a, 3, 10);
}

//CIG P364，自然数数组的排序，n个元素的数组arr，arr中有n个互不相同的自然数
//1~N，实现arr的排序，但是不要把0~N-1直接赋值为1~N来实现
void sort1toN(int a[], int n)
{
	if(!a || n < 2)
		return;
	int tmp, duePosVal;
	for(int i = 0; i < n; ++i)
	{
		tmp = a[i];
		while(a[i] != i+1)
		{
			duePosVal = a[tmp - 1];
			a[tmp - 1] = tmp;
			tmp = duePosVal;
		}
	}
}

//判断数字是否对称
#include <math.h>
bool isMirrorNum(int num)
{
	if(num > -10 && num < 10)
		return true;
	num = abs(num);
	int power = 1;
	for(int i = num; i >= 10; i /= 10)
	{
		power *= 10;
	}
	while(num)
	{
		if(num / power != num % 10)
		{
			return false;
		}
		else
		{
			num = num % power;				//剥头、尾
			num = num / 10;
			power /= 100;
		}
	}
	return true;
}
void _test_sMirrorNum()
{
	cout << isMirrorNum(111);
}




//CIG p238, n皇后问题，在n x n的棋盘上摆n个皇后，任何2个皇后不同行、同列、同斜线
/*
	i， k:行
	j:列
	col[i] : 第i行皇后所在的列数
*/
bool NQueenIsValid(int *col, int i, int j)
{
	for(int k = 0; k < i; ++k)
	{
		if(j == col[k] || ( abs(col[k] - j) == abs(i - k)))
			return false;
	}
	return true;
}
int doNQueen(int i, int *col, int n)
{
	if(n == i)
		return 1;
	int res = 0;
	for(int j = 0; j < n; ++j)		//这个循环会递归调用多次，所以其实是逐行放置皇后，给每一行的皇后找合适的列数
	{
		if(NQueenIsValid(col, i, j))	//判断这个皇后和她上面的各行的皇后是否相克
		{
			col[i] = j;
			res += doNQueen(i+1, col, n);	//每一行皇后放置方法数 相加
		}
	}
	return res;
}
int NQueen(int n)
{
	if(n < 1)
		return 0;
	int *col = new int[n];
	return doNQueen(0, col, n);
}
void _test_NQueen()
{
	cout << NQueen(1) <<endl;
	cout << NQueen(2) <<endl;
	cout << NQueen(8) <<endl;
}
//1-1; 2 3 - 0; 8 - 92


/*
求数组中两两之差绝对值最小的值
这不就是求数轴上最接近点对吗？nlogn

在数组元素较大，如几万，甚至几千万的时候，所有的传统算法都会吃不消的。

这时候我们如果追求高效的话，只能以空间来换取效率，具体算法如下：
1）开辟512M空间（2的32次方bit）的“标识数组”来标识每个整数；
2）遍历1次整个整数数组，将出现过的整数在对应“标识数组”中置‘1’；未出现过的当然还是‘0’；
3）再遍历一次“标识数组”统计“标识数组中”连续‘0’的个数，取最小值便是。
*/
void minAbsSub()
{
	
}

int main()
{
//	_test_replaceBlank();
//	_test_addToTail();
//	_test_rmNode();
//	_test_printFromEnd_digui();
//	_test_minInRotate();
//	_test_fabonacci_1();
//	_test_bit_count();
//	_test_exp();
//	_test_rmNodeO1();
//	_test_reorderOddEven();
//	_test_minStack();
//	_test_maxSumOfSubArr();
//	_test_countOf1Betweent1AndN();
//	_test_findNthUgly();
	// _test_findFirstSingle();
//	_test_firstCommonNode();
//	_tset_firstKInSortedArr();
//	_test_treeDepth_digui();
//	_test_findNumbersWithSum();
//	_test_reverseStr();
//	_test_josephuseCircle();
//	_test_sum1ToN();
//	_test_addWithoutStd();
//	_test_isListMirror();
//	_test_isBst();
//	_test_climbStairs123();
//	_test_NQueen();
//	_test_isNinMatrix();
//	_test_saveLatestNifstream();
	_test_ThreadRunInOrder();
	// _test_tenInJiecheng();
//	_test_reverseStack();
//	_test_sortStackWithOneStack();
//	_test_printCommonValueOfTwoOrderedList();
//	_test_rmMiddleNode();
//	_test_reverseList();
//	_test_reverseDoubleList();
//	_test_rmDumplicateNodeInDisorderedList();
//	_test_selectSortOfList();
//	_test_serialTreeByPre();
//	_test_coinChange();
//	_test_coinChange_dp();
//	_test_sMirrorNum();
//	_test_package01();
//	__test_maxValueOfSub();
//	__test_rand1to7();
	return 0;
}
 
 
 
