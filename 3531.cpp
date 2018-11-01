//标！备份用。
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn(100005);
const int INF(0x7fffffff-1);
int n,dA[maxn],dB[maxn],nextA[maxn],nextB[maxn],nextAB[maxn][18],DA[maxn][18],DB[maxn][18],pos[maxn];
struct node{int h,id;}h[maxn];
bool cmp(node x,node y){return x.h<y.h;}
void loading()
{   sort(h+1,h+n+1,cmp);
    int left[maxn]={0},right[maxn]={0};
    for(int i=1;i<=n;i++){pos[h[i].id]=i;left[i]=i-1;right[i]=i+1;}
    for(int i=1;i<n;i++)
    {
		int p=pos[i];
		int p1=left[left[p]],p2=left[p],p3=right[p],p4=right[right[p]];
      	int diff1=abs(h[p1].h-h[p].h),diff2=abs(h[p2].h-h[p].h);
      	int diff3=abs(h[p3].h-h[p].h),diff4=abs(h[p4].h-h[p].h);
      	if(diff2<=diff3&&p2) nextB[i]=h[p2].id,dB[i]=diff2;
        	else nextB[i]=h[p3].id,dB[i]=diff3;
      	int h0=INF,p0=0;
      	if(h0>diff1&&h[p1].id!=nextB[i]&&p1){h0=diff1;p0=p1;}
      	if(h0>diff2&&h[p2].id!=nextB[i]&&p2){h0=diff2;p0=p2;}
      	if(h0>diff3&&h[p3].id!=nextB[i]&&p3){h0=diff3;p0=p3;}
      	if(h0>diff4&&h[p4].id!=nextB[i]&&p4){h0=diff4;p0=p4;}
      	if(p0<=n)nextA[i]=h[p0].id;
        	else nextA[i]=p0;
      	dA[i]=h0;
      	right[left[p]]=right[p];
      	left[right[p]]=left[p];
   	}
}
void waiting()
{
	for(int i=1;i<n;i++)
    {
		DA[i][0]=dA[i];
        DB[i][0]=dB[nextA[i]];
        nextAB[i][0]=nextB[nextA[i]];
    }
    for(int j=1;j<=17;j++)//倍增表
       for(int i=1;i<n;i++)
       {
		   nextAB[i][j]=nextAB[nextAB[i][j-1]][j-1];
           if(!nextAB[i][j])continue;
           DA[i][j]=DA[i][j-1]+DA[nextAB[i][j-1]][j-1];
           DB[i][j]=DB[i][j-1]+DB[nextAB[i][j-1]][j-1];
       }
}
void Begin()
{
	int Limit,ans=0,h0=-INF;
    double minn=INF;
    scanf("%d",&Limit);
    for(int i=1;i<n;i++)
    {   
		int p=i;
        long long SA=0,SB=0;
        for(int j=17;j>=0;j--)
            if(nextAB[p][j]&&SA+SB+DA[p][j]+DB[p][j]<=Limit)
            {
				SA+=DA[p][j];
                SB+=DB[p][j];
                p=nextAB[p][j];
            }
        if(nextA[p]<=n&&SA+SB+DA[p][0]<=Limit)SA+=DA[p][0];
        double tem;
        if(!SB)tem=INF;
        else tem=double(SA)/double(SB);
        if(tem<minn||(tem==minn&&h0<h[pos[i]].h))
        {
			ans=i;
            h0=h[pos[i]].h;
            minn=tem;
        }
    }
    if(minn==INF&&h0<h[pos[n]].h)
    {
		h0=h[pos[n]].h;
       	ans=n;
    }
    printf("%d\n",ans);
    int m,p;
    scanf("%d",&m);
    while(m--)
    {
		scanf("%d%d",&p,&Limit);
        long long SA=0,SB=0;
        for(int j=17;j>=0;j--)
            if(nextAB[p][j]&&SA+SB+DA[p][j]+DB[p][j]<=Limit)
            {
				SA+=DA[p][j];
                SB+=DB[p][j];
                p=nextAB[p][j];
            }
        if(nextA[p]<=n&&SA+SB+dA[p]<=Limit)SA+=dA[p];
        printf("%lld %lld\n",SA,SB);
    }
}
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&h[i].h);h[i].id=i;}
    loading();
    waiting();
    Begin();
}