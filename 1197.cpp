#include<iostream>
using namespace std;
int n,x,y,z,root=0;
struct treetype{int data,prt,lch,rch;}tree[105];
void dfs(int v)
{
	if(!v) return;
	dfs(tree[v].lch);
	dfs(tree[v].rch);
	cout<<v<<endl;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cin>>tree[x].lch>>tree[x].rch;
		tree[tree[x].lch].prt=tree[tree[x].rch].prt=x;
	}
	for(int i=1;i<=n;i++)
		if(!tree[i].prt)root=i;
	dfs(root);
	return 0;
}