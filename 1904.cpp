#include<iostream>
#include<algorithm>
using namespace std;
int n,rank[55]={0},examt;
struct node{int sco;string name;}ss[10005];
bool cmp(node a,node b)
{return a.sco>b.sco||(a.sco==b.sco&&a.name=="JLY");}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ss[i].name;
	cin>>examt;
	for(int j=1;j<=examt;j++)
	{
		for(int i=1;i<=n;i++)
		{
			int score=0;
			string str;
			cin>>score>>str;
			for(int i=1;i<=n;i++)
				if(str==ss[i].name)
					ss[i].sco+=score;
		}
		sort(ss+1,ss+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(ss[i].name=="JLY")rank[j]=i;
	}
	for(int i=1;i<=examt;i++)cout<<rank[i]<<endl;
	return 0;
}