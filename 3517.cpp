#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
string str,trans;
ll n,P[500005]={0},nx[500005]={0},maxl[500005]={0},ans=0;
char buffer[500005];
void Manacher()
{
    ll id=0;
    for(int i=1;i<=n;i++)
    {
        (id+P[id]>i)?P[i]=min(P[2*id-i],id+P[id]-i):P[i]=1;
        while(str[i-P[i]]==str[i+P[i]]) P[i]++;
        if(i+P[i]>id+P[id]) id=i;
    }
}
void Getnx()
{
    nx[1]=0;
    ll j=0;
    for(int i=2;i<=n;i++)
    {
        while(j&&trans[i]!=trans[j+1]) j=nx[j];
        if(trans[i]==trans[j+1]) j++;
        nx[i]=j;
    }
}
void KMP()
{
    ll j=0;
    for(int i=1;i<=n;i++)
    {
        while(j&&trans[j+1]!=str[i]) j=nx[j];
        if(trans[j+1]==str[i]) j++;
        maxl[i]=max(maxl[i-1],j);
    }
}
int main()
{
    scanf("%lld%s",&n,buffer);
    str=buffer;
    str=' '+str;
    trans=str;
    for(int i=1;i<=n/2;i++) swap(trans[i],trans[n-i+1]);
    Manacher();
    Getnx();
    KMP();
    for(int i=1;i<=n;i++) ans=max(ans,P[i]+min(maxl[i-P[i]],n-i+1-P[i]));
    printf("%lld\n",ans*2-1);
    return 0;
}
