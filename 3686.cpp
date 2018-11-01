#include<iostream>
using namespace std;
typedef long long ll;
int n,x,sum[100005]={0},C[200005]={0};
ll ans=0;
inline int Lowbit(int x)
{return x&(-x);}
void Add(int x)
{for(int i=x;i<=2*n+1;i+=Lowbit(i)) C[i]++;}
ll Sum(int x)
{
    ll ret=0;
    for(int i=x;i>=1;i-=Lowbit(i)) ret+=C[i];
    return ret;
}
int main()
{
    scanf("%d%d",&n,&x);
    sum[0]=n+1;
    Add(sum[0]);
    for(int i=1,num;i<=n;i++)
    {
        scanf("%d",&num);
        if(num>=x) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
        ll add=Sum(sum[i]);
        ans+=add;
        Add(sum[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
