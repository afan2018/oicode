#include<bits/stdc++.h>
using namespace std;
struct node{int pos,val;}Q[1000005];
int n,k,seq[1000005]={0},L,R;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",seq+i);
	L=1,R=0;
	for(int i=1;i<k;i++)
	{
		while(R>0&&Q[R].val>seq[i]) R--;
		Q[++R].val=seq[i];
		Q[R].pos=i;
	}
	for(int i=k;i<=n;i++)
	{
		while(L<=R&&Q[R].val>seq[i]) R--;
		Q[++R].val=seq[i];
		Q[R].pos=i;
		while(L<=R&&Q[L].pos+k<=i) L++;
		printf("%d ",Q[L].val);
	}
	printf("\n");
	L=1,R=0;
	for(int i=1;i<k;i++)
	{
		while(R>0&&Q[R].val<seq[i]) R--;
		Q[++R].val=seq[i];
		Q[R].pos=i;
	}
	for(int i=k;i<=n;i++)
	{
		while(L<=R&&Q[R].val<seq[i]) R--;
		Q[++R].val=seq[i];
		Q[R].pos=i;
		while(L<=R&&Q[L].pos+k<=i) L++;
		printf("%d ",Q[L].val);
	}
	printf("\n");
	return 0;
}
