#include<iostream>
#include<algorithm>
using namespace std;
struct node{int nor,sou;}town[10005];
int n,path[10005]={0},maxx=1;
bool cmp(node x,node y)
{
	if(x.nor==y.nor)return x.sou<y.sou;
	return x.nor<y.nor;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>town[i].nor>>town[i].sou,path[i]=1;
	sort(town+1,town+n+1,cmp);
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(town[i].sou>town[j].sou&&path[i]<path[j]+1)
				path[i]=path[j]+1;
	for(int i=1;i<=n;i++)
		if(path[i]>path[maxx])maxx=i;
	cout<<path[maxx];
	return 0;
}
/*
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
*/