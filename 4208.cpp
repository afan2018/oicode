#include<iostream>
#include<map>
using namespace std;
int n,k,seq[100005],var=0;
map<int,int>Map;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>seq[i];
	int maxx=0,j=1;
	for(int i=1;i<=n;i++)
	{
		if(!Map[seq[i]]) var++;
		Map[seq[i]]++;
		while(var>k+1)
		{
			Map[seq[j]]--;
			if(!Map[seq[j++]]) var--;
		}
		maxx=max(maxx,Map[seq[i]]);
	}
	cout<<maxx;
	return 0;
}