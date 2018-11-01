#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int op,ed;}afan[50005];
int n,ansl,ansr;
bool cmp(const node &x,const node &y)
{return x.op<y.op;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>afan[i].op>>afan[i].ed;
	sort(afan+1,afan+1+n,cmp);
	ansl=afan[1].op,ansr=afan[1].ed;
	for(int i=2;i<=n;i++)
	{
		if(ansr>=afan[i].op) ansr=max(ansr,afan[i].ed);
		else
		{
			cout<<ansl<<' '<<ansr<<endl;
			ansl=afan[i].op;
			ansr=afan[i].ed;
		}
	}
	cout<<ansl<<' '<<ansr;
	return 0;
}
