#include<iostream>
#include<algorithm>
using namespace std;
int father[30005]={0},cnt[30005]={0};
bool cmp(int x,int y)
{return x>y;}
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
	if(fa1==fa2)return;
	father[fa1]=father[fa2];
}
int main(){
	int n,m,p,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		Union(a,b);
	}
	for(int i=1;i<=n;i++)
	cnt[Getfather(i)]++;
	sort(cnt+1,cnt+n+1,cmp);
	cout<<cnt[1];
	return 0;
}