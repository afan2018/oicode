#include<iostream>
using namespace std;
int tree[505]={0};
int n,root,x,y,k,maxx=0,cnt=0,maxf=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		tree[y]=x;
	}
	for(int i=1;i<=n;i++)
		if(!tree[i]) root=i,cout<<root<<endl;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
			if(tree[j]==i)cnt++;
		if(cnt>maxx){maxx=cnt,maxf=i;}
	}
	cout<<maxf<<endl;
	for(int i=1;i<=n;i++)
		if(tree[i]==maxf)cout<<i<<' ';
	return 0;
}