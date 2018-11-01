#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
#include<set>
using namespace std;
map<long long,long long>Map;
set<long long>Set;
long long t,n,seq[500005]={0},ref[500005]={0},cnt=0,c[500005]={0},ans=0;
inline long long Lowbit(long long x)
{return x&(-x);}
long long Sum(long long x)
{
	long long ret=0;
	for(long long i=x;i;i-=Lowbit(i))
		ret+=c[i];
	return ret;
}
void Insert(long long x)
{
	for(long long i=x;i<=cnt;i+=Lowbit(i))
		c[i]++;
}
void Init()
{
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&seq[i]);
		Set.insert(seq[i]);
	}
	for(set<long long,long long>::iterator it=Set.begin();it!=Set.end();it++)
		Map[*it]=++cnt;
	for(long long i=1;i<=n;i++)
		seq[i]=Map[seq[i]];
}
void Solve()
{
	for(long long i=n;i;i--)
	{
		ans+=Sum(seq[i]-1);
		Insert(seq[i]);
	}
	printf("%lld\n",ans);
}
void Clear()
{
	Map.clear();
	Set.clear();
	memset(seq,0,sizeof(seq));
	memset(c,0,sizeof(c));
	cnt=0;
	ans=0;
}
int main()
{
	while(1)
	{
		scanf("%lld",&n);
		if(n==0) break;
		Init();
		Solve();
		Clear();
	}
	return 0;
}