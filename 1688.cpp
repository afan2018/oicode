#include<iostream>
using namespace std;
long a[21]= {0},s[21]= {0},f[21][21]= {0},v[21][21]= {0},s1=0;
void out(long t,long w)
{
	if(t==w)
	{cout<<a[t];return;}
	cout<<'(';
	out(t,v[t][w]);
	cout<<'+';
	out(v[t][w]+1,w);
	cout<<')';
}
long jia(long t,long w)
{
	long x=0,y=0;
	if(t==w)return a[t];
	if(t==v[t][w]&&v[t][w]+1==w)
	{
		cout<<a[t]+a[w]<<' ';
		return a[t]+a[w];
	}
	if(t<=v[t][w])x=jia(t,v[t][w]);
	if(v[t][w]+1<=w)y=jia(v[t][w]+1,w);
	cout<<x+y<<' ';
	return x+y;
}
int main()
{
	long n,i,j,k,t,min;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(i=n-1; i>0; i--)
		for(j=i+1; j<=n; j++)
		{
			min=99999999;
			for(k=i; k<j; k++)
				if(f[i][k]+f[k+1][j]<min)
				{
					min=f[i][k]+f[k+1][j];
					t=k;
				}
			f[i][j]=min+s[j]-s[i-1];
			v[i][j]=t;
		}
	out(1,n);
	cout<<endl<<f[1][n]<<endl;
	k=jia(1,n);
	return 0;
}