#include <iostream>
#include <algorithm>
using namespace std;
long long st[100005]={0},ed[100005]={0},n,m,ans=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>st[i]>>ed[i],ans+=abs(st[i]-ed[i]);
	st[n+1]=m,ed[n+1]=0;
	sort(st+1,st+n+2);
	sort(ed+1,ed+n+2);
	for(int i=1;i<=n+1;i++)
		ans+=abs(st[i]-ed[i]);
	cout<<ans;
	return 0;
}