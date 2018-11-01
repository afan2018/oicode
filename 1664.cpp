#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
double lim,vvv,val[100005]={0},tot=0;
int flag=1,n,x,y,prt[100005]={0},a[100005]={0},b[100005]={0},cnt=0;
struct node{int a,b;double l;
	bool operator <(node const &T)const
	{
		return(l<T.l);
	}
}afan[100005];
int getfather(int x)
{
	if(prt[x]==x)return x;
	prt[x]=getfather(prt[x]);
	return prt[x];
}
void Kruskal()
{
	int ccnt=0;
	for(int i=1;i<=n;i++)prt[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int faa=getfather(afan[i].a),fab=getfather(afan[i].b);
		if(faa!=fab)
		{
			tot+=afan[i].l;
			prt[faa]=fab;
			ccnt++;
			if(ccnt==n-1)break;
		}
	}
	if(ccnt<n-1||tot>lim){cout<<"Impossible\n",flag=0;return;}
}
int main(){
	cin>>lim>>n;
	while(cin>>x>>y>>vvv)
		afan[++cnt].a=x,afan[cnt].b=y,afan[cnt].l=vvv;
	sort(afan+1,afan+cnt+1);
	Kruskal();
	if(flag)cout<<fixed<<setprecision(2)<<tot<<endl;
	return 0;
}
/*
100.0
4
1 2 2.0
1 3 4.2
1 4 6.7
3 4 4.0
2 4 10.0
*/