#include<iostream>
using namespace std;
int tree[505]={0};
int n,root=1,x,y,quene[505]={0};
void bfs(int v)
{
	int head=1,tail=1;
	quene[1]=v;
	while(head<=tail)
	{
		cout<<quene[head]<<' ';
		for(int i=1;i<=n;i++)
			if(tree[i]==quene[head])
				quene[++tail]=i;
		head++;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		tree[x]=y;
	}
	while(tree[root])root=tree[root];
	bfs(root);
	return 0;
}