#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,sum=0,ans=0;
struct node{long long eat,move;}cow[100005];
bool cmp(const node &x,const node &y)
{return (double)x.move/(double)x.eat<(double)y.move/(double)y.eat;}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>cow[i].move>>cow[i].eat,sum+=cow[i].eat;;
	sort(cow+1,cow+n+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		sum-=cow[i].eat;
		ans+=2*sum*cow[i].move;
	}
	cout<<ans;
	return 0;
}

