#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll MOD (1000000009ll);
struct node{ll col,x;}oil[100005];
ll n,m,ans=1;
inline bool cmp(const node &a,const node &b)
{return a.x<b.x;}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		char ch;
		cin>>ch>>oil[i].x; 
		oil[i].col=ch-'A';
	}
	sort(oil+1,oil+m+1,cmp);
	for(ll i=1;i<m;i++)
	{
		if(oil[i].col==oil[i+1].col) continue;
		ans=(ans*((oil[i+1].x-oil[i].x)%MOD))%MOD;
	}
	printf("%lld",ans);
	return 0;
}