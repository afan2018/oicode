#include<iostream>
using namespace std;
int a[10001]={0},b[101]={0},n,m,s=0;
int main()
{  int i,j,minn=0xfffffff,t,maxx=0;
   cin>>n>>m;
   for(i=1;i<=n;i++)cin>>a[i];
   if(m>n)m=n;
   for(i=1;i<=n;i++)
   {    minn=0xfffffff;
        for(j=1;j<=m;j++)
	if(minn>b[j]){minn=b[j];t=j;}
        b[t]+=a[i];
   }
   for(i=1;i<=m;i++)
       if(maxx<b[i])maxx=b[i];
   cout<<maxx;
}
