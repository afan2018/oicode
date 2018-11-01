#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int father[30005]={0},before[30005]={0},countt[30005]={0};
int getint()
{
	int bj=1;
	char ch=getchar();
	if(ch=='-')bj=-1;
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
		if(ch=='-')bj=-1;
	}
	int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+(ch-'0');
		ch=getchar();
	}
	return ret*bj;
}
int abs(int x,int y)
{
	if(x>y)return x-y;
	else return y-x;
}
int Getfather(int x)
{
	int temp;
	if(father[x]==x)return x;
	temp=Getfather(father[x]);
	before[x]+=before[father[x]];
	father[x]=temp;
	return father[x];
}
void Union(int x,int y)
{
	int fa1,fa2;
	fa1=Getfather(x),fa2=Getfather(y);
	//if(fa1==fa2)return;
	father[fa1]=fa2;
	before[fa1]=countt[fa2];
	countt[fa2]+=countt[fa1];
}
void Ask(int x,int y)
{
	if(Getfather(x)!=Getfather(y)){printf("-1\n");return;}
	long long tot=abs(before[x],before[y])-1;
	printf("%lld\n",tot);
}
int main(){
	int n,m,a,b;
	char ch;
	n=getint();
	for(int i=1;i<=30003;i++)father[i]=i,countt[i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&ch);
		a=getint();b=getint();
		if(ch=='M'){
			Union(a,b);
		}
		else {
			Ask(a,b);
		} 
	}
	return 0;
}