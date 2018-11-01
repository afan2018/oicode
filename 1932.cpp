#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool map[70][70],odd[70];
int ans[1000]={0},n,sum=0,minn=0x7f7f7f7f,sta=0,cnt=0;
int init()
{
	cin>>n;
	char ch1,ch2,a,b; 
	memset(map,false,sizeof(map));
	memset(odd,false,sizeof(odd));
	for(int i=1;i<=n;i++)
	{
		cin>>ch1>>ch2;
		a=ch1-'A',b=ch2-'A'; 
		map[a][b]=1,map[b][a]=1;
	    odd[a]=!odd[a],odd[b]=!odd[b];
		if(a<minn)minn=a;
		if(b<minn)minn=b;
	}
	for(int i=65;i>=0;i--)
		if(odd[i]%2)
		{
			//cout<<char('A'+i)<<' ';
			sum++,minn=i;
		}
	if(!sum) return 1;
	if(sum==2) return 1;
	else return 0;
}
void DFS(int dep)
{
	for(int i=0;i<=65;i++)
		if(map[dep][i])
		{
			map[dep][i]=map[i][dep]=false;
			DFS(i);
		}
	ans[++cnt]=dep;	
	return;
}
int main(){
	int flag=0;
	flag=init();
	if(flag)
	{
		DFS(minn);
		for(int i=cnt;i>=1;i--)
			cout<<char(ans[i]+'A');
	}
	else cout<<"No Solution\n";
	//cout<<sum<<endl;
	return 0;
}