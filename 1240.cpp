#include<iostream>
using namespace std;
int a[30][2]={0};
int dfs(int k,int w)
{
	if(w==1)cout<<char(k-1+'A');
	if(a[k][0]!=0)dfs(a[k][0],w);
	if(w==2)cout<<char(k-1+'A');
	if(a[k][1]!=0)dfs(a[k][1],w);
	if(w==3)cout<<char(k-1+'A');
	return 0;
}
int main()
{
	int n,i,j,m,b;
	char s,ch;
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>s;
		b=i;
		for(j=1;1;j++)
		{
			cin>>ch;
			if(ch=='0') break;
			m=ch-'A'+1;
			if(j==1) a[i][0]=m;
			else a[b][1]=m;
			b=m;
		}
	}
	dfs(1,1);
	cout<<endl;
	dfs(1,2);
	cout<<endl;
	dfs(1,3);
	cout<<endl;
}
/*
7
A B C D 0
B E 0
C F G 0
E 0
D 0
F 0
G 0
*/