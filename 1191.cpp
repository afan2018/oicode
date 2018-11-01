#include<iostream>
using namespace std;
int tree[505]={0};
int n,root=1,x,y;
void dfs(int v)
{
	
	for(int i=1;i<=n;i++)
		if(tree[i]==v) dfs(i);
	cout<<v<<' ';
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		tree[x]=y;
	}
	while(tree[root])root=tree[root];
	dfs(root);
	return 0;
}
