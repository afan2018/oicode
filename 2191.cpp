#include<iostream>
using namespace std;
const int one=10000000;
int tst=0,n,k,f[1005][1005][5]={0},seq[1005]={0};
void print(int a[])//输出
{
     cout<<a[a[0]];
     for(int i=a[0]-1;i>=1;i--)
        for(int j=one/10;j>=1;j/=10)cout<<a[i]/j%10;
}
void plu(int c[],int a[],int b[])//高精度加法c=a+b
{
     c[0]=max(a[0],b[0]);
     for(int i=1;i<=c[0];i++)c[i]=a[i]+b[i];
     for(int i=1;i<=c[0];i++)c[i+1]+=c[i]/one,c[i]%=one;
     if(c[c[0]+1]>0)c[0]++;
}
int main(){
//	cin>>tst;
//	while(tst--)
//	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>seq[i],seq[i]=(seq[i]%k+k)%k;
		f[1][seq[1]][0]=f[1][seq[1]][1]=1;
		for(int i=2;i<=n;i++)
			for(int j=0;j<k;j++)
				plu(f[i][j],f[i-1][((j+seq[i])%k+k)%k],f[i-1][((j-seq[i])%k+k)%k]);
		if(!f[n][0][0]) cout<<"Not Divisible.\n";
		else print(f[n][0]);
//	}
	return 0;
}