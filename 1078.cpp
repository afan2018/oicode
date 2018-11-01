#include<iostream>
using namespace std;
int n,maxx=1,seq[1005]={0},len[1005]={0};
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>seq[i],len[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(seq[i]>=seq[j]&&len[j]+1>len[i])
				len[i]=len[j]+1;
	for(int i=1;i<=n;i++)
		if(len[i]>len[maxx])maxx=i;
	cout<<len[maxx]<<'\n';
	return 0;
}
/*
14
13 7 9 16 38 24 37 18 4 19 21 22 63 15
*/