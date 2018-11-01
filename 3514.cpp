#include <iostream>
#include <cstring>
using namespace std;
int n,m,map[30][30]={0},rd[30]={0},rd1[30]={0},ans[30]={0};
int Topsort()
{
	int cnt=0,bj=0;
	ans[0]=0;
	while(1)
	{
		cnt=1;
		int tmp=ans[0];
		while(cnt<=n) 
		{
			if(rd1[cnt]==0){ans[++ans[0]]=cnt;rd1[cnt]=-1;}
			cnt++;
		}
		if(ans[0]-tmp>1) bj=1;
		if(ans[0]==n) break;
		if(ans[0]==tmp) return -1;
		for(int j=tmp+1;j<=ans[0];j++)
		{
			for(int k=1;k<=n;k++)
				if(map[ans[j]][k]) rd1[k]--;}
	}
	if(bj==0) return 1;
	return 0;
}
int main()
{
	cin>>n>>m;
	int idx;
	for(int i=1;i<=m;i++)
	{
		string str;
		cin>>str;
		if(map[str[0]-'A'+1][str[2]-'A'+1]) continue;
		map[str[0]-'A'+1][str[2]-'A'+1]=1;
		rd[str[2]-'A'+1]++;
		memcpy(rd1,rd,sizeof(rd1));
		idx=Topsort();
		if(idx==1) 
		{
			cout<<"Sorted sequence determined after "<<i<<" relations: ";
			for(int i=1;i<=ans[0];i++)
			cout<<char(ans[i]-1+'A');
			cout<<'.';
			return 0;
		}
		if(idx==-1) {cout<<"Inconsistency found after "<<i<<" relations.\n";return 0;}
	}
	if(idx==0) cout<<"Sorted sequence cannot be determined.\n";
	return 0;
}
