#include<iostream>
using namespace std;
int tree[505]={0};
int n,root,x,y,k,sum=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		tree[y]=x;
	}
	for(int i=1;i<=n;i++)
		if(!tree[i]) sum++;
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
		if(!tree[i]) cout<<i<<" ";
	return 0;
}