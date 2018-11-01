#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
inline bool cmp(const int x,const int y)
{return x>y;}
int a[1005]={0},b[1005]={0},c[1005]={0},d[1005]={0};
int main()
{
	int M,N,K,L,D;
	int i,j;//变量区域 
	int x1,y1,x2,y2;	
	cin>>M>>N>>K>>L>>D;
	for(i=1;i<=D;i++)
	{
		 cin>>x1>>y1>>x2>>y2;
		 if(x2==x1)
		 {
		 	if(y1<y2)b[y1]++;
		 	else b[y2]++;
		 }
		 	
		 else 
		 {
		 	if(x1<x2)a[x1]++;
		 	else a[x2]++;
		 }
	} 
	
	for(i=1;i<=M-1;i++)c[i]=a[i];
	for(i=1;i<=N-1;i++)d[i]=b[i];
	sort(a+1,a+M,cmp);
	int tmp[1005]={0};
	for(i=1;i<=K;i++)
		for(j=1;j<=M-1;j++)
			if(a[i]==c[j])
			{
				tmp[i]=j;
				c[j]=-1;
				break;
			}
	sort(tmp+1,tmp+K+1);
	for(int i=1;i<=K;i++)
		cout<<tmp[i]<<' ';
	cout<<endl;
	//以上为行
	memset(tmp,0,sizeof(tmp));
	sort(b+1,b+N,cmp);
	for(i=1;i<=L;i++)
		for(j=1;j<=N-1;j++)
			if(b[i]==d[j])
			{
				tmp[i]=j;
				d[j]=-1;
				break;
			}
	sort(tmp+1,tmp+L+1);
	for(int i=1;i<=L;i++)
		cout<<tmp[i]<<' ';
	cout<<endl;
	return 0;
}