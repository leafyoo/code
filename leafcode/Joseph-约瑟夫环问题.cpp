/* 
问题描述：

已知n个人（以编号0，2，3...n-1分别表示）围坐在一起。从编号为0的人开始报数，数到k的那个人出列；他的下一个人又从1开始报数，数到k的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列，最后一个出列的人为胜利者。求胜利者编号.
 */



//jor p246, 约瑟夫环，从有n个节点的环里每次删除第m个结点
int Joseph_list(int n, int m)
{
	if(n < 1 || m < 1) return 0;
	
    list<int> lst;
	for(int i = 0; i < n; ++i)
		lst.push_back(i);

	list<int>::iterator it = lst.begin(), next;
	while(lst.size() > 1)
	{
		for(int i = 1; i < m; ++i)
		{
			++it;
			if(it == lst.end()) it = lst.begin();
		}

		next = it;						//错误:it+1;：no match for ‘operator+’ (
        advance(next, 1);               //向前移动1个节点
        if(next == lst.end()) next = lst.begin();

		lst.erase(it);
		it = next;
	}

	return *it;
}



/* n =5,k =3 设约瑟夫环最后一个出列的人为 Joseph(5,3),那么存在如下关系
　　　　　　　　　　Joseph(5,3) = (Joseph(4,3)+k) % n;
　　　　　　　　　　...
　　　　　　　　　　Joseph(n,k) = (Joseph(n-1,k)+k) % n （n>1）;  

 */
int Joseph_recursion(int m,int k)
{
    if(m<=0||k<=0)
        return -1;
    else
    {
        if(m==1)
            return 0;
        else
            return ((Joseph(m-1,k) + k) % m);
    }
}

/* 递归方法二：如果输出整个出队的顺序 */
/* 
    for(int i=1;i<=6;i++)
    {
        cout<<Joseph(6,3,i)<<endl;
    }
 */
int Joseph(int m,int k,int i)
{
    if(m<=0||k<=0||m<i)
        return -1;
    else
    {
        if(i==1)
            return (m+k-1)%m;
        else
            return ((Joseph(m-1,k,i-1)+k)%m);
    }
}

