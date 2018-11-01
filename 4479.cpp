#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int id,val;}a[55];
int n,la=0;
string str;
bool cmp(const node &a,const node &b)
{return a.val>b.val||(a.val==b.val&&a.id<b.id);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		cin>>str;
		for(int j=0;j<n;j++)
		{
			if(str[j]=='-') continue;
			if(str[j]=='L') a[j+1].val+=3;
			if(str[j]=='D') a[i].val++,a[j+1].val++;
			if(str[j]=='W') a[i].val+=3;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].val<la) break;
		printf("%d ",a[i].id);
		la=a[i].val;
	}
	return 0;
}
