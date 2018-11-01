#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int val,bj;}cut[40005];
int n,m,cuta[40005]={0},cutb[40005]={0},a,b,ans=0;
bool cmp(const node &a,const node &b)
{return a.val>b.val;}
int main()
{
	cin>>n>>m;
	n--,m--;
	for(int i=1;i<=n;i++)
		cin>>cut[i].val;
	for(int i=1;i<=m;i++)
		cin>>cut[i+n].val,cut[i+n].bj=1;
	a=1,b=1;
	sort(cut+1,cut+n+m+1,cmp);
	for(int i=1;i<=n+m;i++)
	{
		if(cut[i].bj)
		{
			b++;
			ans+=a*cut[i].val;
		}
		else
		{
			a++;
			ans+=b*cut[i].val;
		}
	}
	cout<<ans;
	return 0;
}

