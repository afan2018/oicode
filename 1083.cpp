#include<iostream>
using namespace std;
int father[5005]={0};
int Getfather(int x)
{
	if(father[x]==x)return x;
	father[x]=Getfather(father[x]);
	return father[x];
}
void Judge(int x,int y)
{
	int fa1,fa2;
	fa1=Getfather(x),fa2=Getfather(y);
	if(fa1==fa2)cout<<"Yes\n";
		else cout<<"No\n";
}
void Union(int x,int y)
{
	int fa1,fa2;
	fa1=Getfather(x),fa2=Getfather(y);
	if(fa1!=fa2)father[fa1]=father[fa2];
}
int main(){
	int n,m,p,a,b;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		Union(a,b);
	}
	for(int i=1;i<=p;i++)
	{
		cin>>a>>b;
		Judge(a,b);
	}
	return 0;
}