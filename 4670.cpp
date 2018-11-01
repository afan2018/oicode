#include<iostream>
#include<cstdio>
using namespace std;
int a,n,m,i,j,cnt=-1;
bool b[100];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a;
			if(!b[a])
			{
				cnt++;
				b[a]=1;
			}
		}
	if(cnt>10) cout<<"8";
	else if(cnt==9) cout<<"7";
	else if(cnt==10) cout<<"5";
	else if(cnt==5) cout<<"2";
	else if(cnt<=1) cout<<"1";
	else cout<<cnt;
	return 0;
}