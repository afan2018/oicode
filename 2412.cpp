#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int fr,to,val;}edge[20005],New;
int n,m,maxx=0,suc=0,len=0,fa[20005]={0},ans=0;
void Insert()
{
	int pos=0;
	for(int i=len;i>=1;i--)
		if(edge[i].val<=New.val)
			{pos=i;break;}
	for(int i=len;i>pos;i--)
		edge[i+1]=edge[i];
	edge[pos+1]=New;
	len++;
}
int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
bool Kruskal()
{
	ans=0,maxx=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=len;i++)
	{
		int fa1=Getfa(edge[i].fr);
		int fa2=Getfa(edge[i].to);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			ans+=edge[i].val;
			maxx=edge[i].val;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	return cnt<n-1?false:true;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>New.fr>>New.to>>New.val;
		if(suc&&New.val>maxx) {cout<<ans<<endl;continue;}
		Insert();
		if(!Kruskal()) 
			cout<<-1<<endl;
		else suc=1,cout<<ans<<endl;
	}
	return 0;
}