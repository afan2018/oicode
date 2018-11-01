#include<iostream>
const int INF=1<<30;
using namespace std;
int flow,vase,val[105][105]={0},met[105][105]={0};
void print(int a,int b)
{
	if(!a) return;
	if(met[a][b]==met[a][b-1]) print(a,b-1);
		else {print(a-1,b-1);cout<<b<<' ';}
}
int main(){
	cin>>flow>>vase;
	for(int i=1;i<=flow;i++)
		for(int j=1;j<=vase;j++)
			cin>>val[i][j];
	met[0][0]=0;
	for(int i=1;i<=flow;i++) met[i][0]=-INF;
	for(int i=1;i<=flow;i++)
		for(int j=1;j<=vase;j++)
			met[i][j]=max(met[i-1][j-1]+val[i][j],met[i][j-1]);
	cout<<met[flow][vase]<<'\n';
	print(flow,vase);
	return 0;
}
