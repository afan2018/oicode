#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int father[30005]={0},cnt=0,ene[30005]={0};
bool vvv[30005];
bool cmp(int x,int y)
{return x>y;}
int Getfather(int x)
{
	if(father[x]==x)return x;
	father[x]=Getfather(father[x]);
	return father[x];
}
void Judge(int x,int y)
{
	int fa1,fa2;
	fa1=Getfather(x),fa2=Getfather(y);
	if(fa1==fa2)cout<<"Yes\n";
		else cout<<"No\n";
}
void Union(int x,int y)
{
	int fa1,fa2;
	fa1=Getfather(x),fa2=Getfather(y);
	//if(fa1==fa2)return;
	father[fa1]=father[fa2];
}
int main(){
	memset(vvv,true,sizeof(vvv));
	int n,m,a,b;
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>ch>>a>>b;
		if(ch=='F')Union(a,b);
		else {
			if(!ene[a])ene[a]=b;
			else Union(ene[a],b);
			if(!ene[b])ene[b]=a;
			else Union(ene[b],a);
		} 
	}
	cnt=0;
	for(int i=1;i<=n;i++)if(vvv[Getfather(i)]){vvv[father[i]]=false,cnt++;}
	cout<<cnt;
	return 0;
}