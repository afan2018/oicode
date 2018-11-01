#include<iostream>
const int INF=0x7fffffff;
using namespace std;
int fmax[105][105]={0},fmin[105][105]={0},sum[105]={0},n,seq[105]={0};
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>seq[i],sum[i]=sum[i-1]+seq[i];
	for(int t=1;t<=n-1;t++)
		for(int op=1;op<=n;op++)
		{
			int ed=op+t;
			fmax[op][ed]=0,fmin[op][ed]=INF;
			for(int i=op;i<=ed-1;i++)
			{
				fmax[op][ed]=max(fmax[op][ed],fmax[op][i]+fmax[i+1][ed]);
				fmin[op][ed]=min(fmin[op][ed],fmin[op][i]+fmin[i+1][ed]);
			}
			fmax[op][ed]+=sum[ed]-sum[op-1];
			fmin[op][ed]+=sum[ed]-sum[op-1];
		}
	cout<<fmin[1][n]<<'\n'<<fmax[1][n];
	return 0;
}
/*
4
13 7 14 6
*/