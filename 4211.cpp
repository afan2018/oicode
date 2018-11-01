#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >heap;
long long n,m,k,cnt=0;
struct node{long long prc,sale;}cow[50005];
bool cmpsale(node a,node b)
{return a.sale<b.sale;}
int main()
{
	cin>>n>>k>>m;
	for(long long i=1;i<=n;i++)
		cin>>cow[i].prc>>cow[i].sale;
	sort(cow+1,cow+n+1,cmpsale);
	for(long long i=1;i<=k&&cow[i].sale<=m;i++)
	{
		m-=cow[i].sale;
		heap.push(cow[i].prc-cow[i].sale);
		cnt=i;
	}
	if(cnt<k) {cout<<cnt;return 0;}
	long long ans=cnt;
	while(cnt<n)
	{
		cnt++;
		long long delta=heap.top();
		if(min(cow[cnt].sale+delta,cow[cnt].prc)<=m)
		{
			ans++;
			if(cow[cnt].sale+delta<cow[cnt].prc)
			{
				m-=cow[cnt].sale+delta;
				heap.pop();
				heap.push(cow[cnt].prc-cow[cnt].sale);
			}
			else m-=cow[cnt].prc;
		}
	}
	cout<<ans;
	return 0;
}
