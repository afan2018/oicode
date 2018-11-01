#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int f[500005]={0},n,m,sum[500005]={0},q[500005]={0};
double Calc(int a,int b)
{return (f[a]-f[b]+sum[a]*sum[a]-sum[b]*sum[b])/(sum[a]-sum[b]);}
int main()
{
	while(cin>>n>>m)
	{
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		memset(q,0,sizeof(q));
		for(int i=1,x;i<=n;i++)
			cin>>x,sum[i]+=sum[i-1]+x;
		int head=1,tail=1;
		q[1]=0,f[0]=0;
		for(int i=1;i<=n;i++)
		{
			while(head<tail&&Calc(q[head],q[head+1])<2*sum[i]) head++;
			int j=q[head];
			f[i]=f[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
			while(head<tail&&Calc(q[tail-1],q[tail])>Calc(q[tail],i)) tail--;
			q[++tail]=i;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
