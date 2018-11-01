#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int seq[15]={0},n,k;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		seq[i]=i;
	int ptr;
	for(int i=2;i<=n;i++)
	{
		ptr=1;
		while(1)
		{
			seq[ptr]++;
			if(seq[ptr]!=seq[ptr+1]) break;
			seq[ptr]=ptr;
			ptr++;
		}
	}
	ptr=k;
	for(int i=seq[ptr];i>=1;i--)
	{
		if(seq[ptr]==i)
		{
			cout<<1;
			ptr--;
		}
		else cout<<0;
	}
	return 0;
}