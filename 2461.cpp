#include<cstdio>
#include<cstring>
using namespace std;
struct node{int val,pos;}Q[2000005];
int seq[2000005]={0},n,L=1,R=0,A[1000005]={0},B[1000005]={0},sum[2000005]={0},ok[1000005]={0};
inline int Getint()
{
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {ret=ret*10+ch-'0';ch=getchar();}
	return ret;
}
int main()
{
	n=Getint();
	for(int i=1;i<=n;i++) A[i]=Getint(),B[i]=Getint();
	for(int i=1;i<=n;i++) seq[i]=A[i]-B[i];
	for(int i=1;i<n;i++) seq[n+i]=seq[i];
	for(int i=1;i<2*n;i++) sum[i]=sum[i-1]+seq[i];
	int tp;
	for(int i=1;i<n;i++)
	{
		tp=sum[i];
		while(L<=R&&Q[R].val>tp) R--;
		Q[++R].pos=i;
		Q[R].val=tp;
	}
	for(int i=n;i<2*n;i++)
	{
		tp=sum[i];
		while(L<=R&&Q[R].val>tp) R--;
		Q[++R].pos=i;
		Q[R].val=tp;
		while(L<=R&&Q[L].pos<=i-n) L++;
		ok[i-n+1]=(Q[L].val-sum[i-n])>=0;
	}
	seq[1]=A[1]-B[n];
	for(int i=2;i<=n;i++) seq[n-(i-2)]=A[i]-B[i-1];
	for(int i=1;i<n;i++) seq[n+i]=seq[i];
	for(int i=1;i<2*n;i++) sum[i]=sum[i-1]+seq[i];
	memset(Q,0,sizeof(Q));
	L=1,R=0;
	for(int i=1;i<n;i++)
	{
		tp=sum[i];
		while(L<=R&&Q[R].val>tp) R--;
		Q[++R].pos=i;
		Q[R].val=tp;
	}
	for(int i=n;i<2*n;i++)
	{
		tp=sum[i];
		while(L<=R&&Q[R].val>tp) R--;
		Q[++R].pos=i;
		Q[R].val=tp;
		while(L<=R&&Q[L].pos<=i-n) L++;
		(i==n)?ok[1]|=((Q[L].val-sum[i-n])>=0):ok[(2*n+1)%i]|=((Q[L].val-sum[i-n])>=0);
	}
	for(int i=1;i<=n;i++) ok[i]?puts("TAK"):puts("NIE");
	return 0;
}
