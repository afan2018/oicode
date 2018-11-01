#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,m,i,a[23333]={1},b[23333],k=0,s=0;

while(cin>>n>>m)
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    k=0;
    s=0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n,s<n;i++)
	{
		if(i==n+1)i=1;
		if(a[i]!=0)k++;
		if(k==m)
		{
			m=a[i];
			a[i]=0;
			k=0;
			s++;
			b[s]=i;
		}
 	}
 	for(i=1;i<=n;i++)
 		cout<<b[i]<<" ";
    cout<<endl;
}
return 0;
}
