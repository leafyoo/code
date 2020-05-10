/* 
卡特兰数问题：h(n)=h(0)*h(n-1)+h(1)*h(n-2)+...+h(n-1)*h(0)

计算的解决方法：用动态规划的思想，顺序求出每个h(i)，i从0到n。
 */
int catalan(int n)
{
    vector<int> h(n+1,0);
    h[0]=1;
    h[1]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
            h[i]+=h[j]*h[i-j-1];
    }
	
    return h[n];
}