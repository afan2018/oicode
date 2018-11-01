#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
long long n,m,t[200005]={0},ans=0;
int main()
{
	//freopen("t1.in","r",stdin);
	//freopen("t1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>t[i],q.push(t[i]);
	for(int i=1;i<n;i++)
	{
		int a=q.top();q.pop();
		int b=q.top();q.pop();
		q.push(a+b);
		ans+=a+b;
	}
	cout<<fixed<<setprecision(6)<<double(ans)/double(m);
	return 0;
}
