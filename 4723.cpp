#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int n,rd[30]={0};
bool map[30][30]={0};
string str[105];
queue<int>q;
void TS()
{
	for(int i=0;i<26;i++)
		if(!rd[i]) q.push(i);
	while(!q.empty())
	{
		int fr=q.front();
		q.pop();
		for(int i=0;i<26;i++)
			if(map[fr][i]&&--rd[i]==0)
				q.push(i);
	}
}
int main()
{
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>str[i];
	memset(map,0,sizeof(map));
	for(int i=2;i<=n;i++)
	{
		int len=str[1].length();
		for(int j=0;j<len;j++)
		{
			if(str[i-1][j]==str[i][j]) continue;
			map[str[i-1][j]-'a'][str[i][j]-'a']=1;
			rd[str[i][j]-'a']++;
			break;
		}
	}
	TS();
	for(int i=0;i<26;i++)
		if(rd[i]) {cout<<"impossible";return 0;}
	cout<<"possible";
	return 0;
}