#include<iostream>
#include<algorithm>
using namespace std;
int n;
char kkk[233];
struct star
{long long haogan;
  int biaohao;}a[10005]; 
string name[10005];
inline bool cmp(const star &x,const star &y)
{return x.haogan>y.haogan||(x.haogan==y.haogan&&name[x.biaohao]<name[y.biaohao]);}
int DDS(string name_p)
{
	int l,mid,r;
	l=1;r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(name_p==name[mid])return mid;
		if(name_p<name[mid])r=mid-1;
		else l=mid+1;
	}
}
void F()
{
	int score;
	string name_p;
	scanf("%d",&score);
	scanf("%s",&kkk);
	name_p=kkk;
	//cin>>score>>name_p;
	a[DDS(name_p)].haogan+=score;
}
int main()
{
	int i,m;
	scanf("%d",&n);
	//cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",&kkk);
		name[i]=kkk;
	}
		
		//cin>>name[i];
	sort(name+1,name+1+n);
	for(i=1;i<=n;i++)
	{
		a[i].biaohao=i;
		a[i].haogan=0;
	}
		
			
	scanf("%d",&m);
	//cin>>m;
	for(i=1;i<=m;i++)
		F();
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
		cout<<name[a[i].biaohao]<<" "<<a[i].haogan<<endl; 
	return 0;
}