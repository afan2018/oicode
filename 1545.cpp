#include<iostream>
#include<algorithm>
using namespace std;
struct node{int num,id;}seq[105];
int n,m;
inline bool cmp(const node &a,const node &b)
{return a.num>b.num;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&seq[i].num);
		seq[i].id=i;
	}
	sort(seq+1,seq+n+1,cmp);
	printf("%d %d",seq[m].num,seq[m].id);
	return 0;
}
