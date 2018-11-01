#include<iostream>
using namespace std;
struct node{int x,y;}sit[105];
int n,sum=0;
int s_get(node a,node b)
{return a.x*b.y-b.x*a.y;}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sit[i].x>>sit[i].y;
	sit[0]=sit[n];
	for(int i=0;i<n;i++)
		sum+=s_get(sit[i],sit[i+1]);
	cout<<sum/2;
	return 0;
}