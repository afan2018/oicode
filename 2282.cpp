#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int op,ed,num;}afan[5005];
int n,m,pltd[30005]={0},ans=0;
bool cmp(const node &x,const node &y)
{return x.ed<y.ed;}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>afan[i].op>>afan[i].ed>>afan[i].num;
	sort(afan+1,afan+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int tree=0;
		for(int j=afan[i].op;j<=afan[i].ed;j++)
			if(pltd[j]) tree++;
		if(tree>=afan[i].num) continue;
		for(int j=afan[i].ed;j>=afan[i].op;j--)
		{
			if(!pltd[j])
			{
				pltd[j]=1;
				tree++;
				ans++;
				if(tree==afan[i].num) break;
			}
		}
	}
	cout<<ans;
	return 0;
}
