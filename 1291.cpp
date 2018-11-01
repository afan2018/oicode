#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x7fffffff;
int ans[1005]={0},mot[1005]={0},n,m,dep=0;
bool suc=0;
void DFS(int a,int b,int k)
{
	if(k>dep) return;
	if(a==1&&k==dep&&b>mot[k-1])
	{
		mot[k]=b;
		if(!suc||b<ans[k]) 
			memcpy(ans,mot,sizeof(mot));
		suc=1;
		return;
	}
	int lowb=max(b/a,mot[k-1])+1;
	int upb=(dep-k+1)*b/a;
	upb=(upb>INF)?INF:upb;
	upb=(suc&&upb>ans[dep]-1)?ans[dep]-1:upb;
	for(int i=lowb;i<=upb;i++)
	{
		mot[k]=i;
		int red=__gcd(a*i-b,b*i);
		DFS((a*i-b)/red,(b*i)/red,k+1);
	}
}
int main()
{
	cin>>n>>m;
	int red=__gcd(n,m);
	suc=0,mot[0]=1;
	while(++dep)
	{
		DFS(n/red,m/red,1);
		if(suc)
		{
			for(int i=1;i<=dep;i++)
				cout<<ans[i]<<' ';
			break;
		}
	}
	return 0;
}