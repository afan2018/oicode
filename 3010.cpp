#include <iostream>
using namespace std;
int nx[100005]={0},pr[100005]={0},in[100005]={0},n,m;
void Insert(int x,int y)
{
	nx[y]=nx[x];
	pr[y]=x;
	nx[x]=y;
	pr[nx[y]]=y;
}
void Delete(int x)
{
	if(in[x])
	{
		nx[pr[x]]=nx[x];
		pr[nx[x]]=pr[x];
		in[x]=0;
	}
}
void Print()
{
	int x=0;
	while(1)
	{
		if(x) cout<<' ';
		x=nx[x];
		if(x==n+1) break;
		cout<<x;
	}
	cout<<endl;
}
int main()
{
	cin>>n;
	nx[0]=n+1;
	pr[n+1]=0;
	Insert(0,1);
	in[1]=1;
	for(int i=2,num,idx;i<=n;i++)
	{
		cin>>num>>idx;
		if(!idx) num=pr[num];
		Insert(num,i);
		in[i]=1;
	}
	cin>>m;
	for(int i=1,num;i<=m;i++)
	{
		cin>>num;
		Delete(num);
	}
	Print();
	return 0;
}