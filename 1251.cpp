#include<iostream>
#include<cstring>
using namespace std;
bool map[20][20],odd[20];
int ans[20]={0},n,dot=1,sum=0;
bool init()
{
	cin>>n;
	memset(map,false,sizeof(map));
	memset(odd,false,sizeof(odd));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>map[i][j];
			if(map[i][j])odd[i]=!odd[i];
		}
	for(int i=n;i>=1;i--)
		if(odd[i])dot=i,sum++;
	if(!sum||sum==2)return true;
	else return false;
}
void DFS(int dep)
{
	for(int i=1;i<=n;i++)
		if(map[dep][i])
		{
			map[dep][i]=map[i][dep]=false;
			DFS(i);
		}
	ans[++ans[0]]=dep;
}
int main(){
	std::ios::sync_with_stdio(false);
	if(init())
	{
		DFS(dot);
		for(int i=ans[0];i>=1;i--)
			if(i==1) cout<<ans[i];
				else cout<<ans[i]<<"->";
	}
	else cout<<"No Solution!";
	return 0;
}
