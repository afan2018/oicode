#include<iostream>
using namespace std;
const int M=0x7ffffff;
int main()
{
 int f[10001],a[101],b[101],m,n,p,i,j;
 cin>>n>>m;//n 种硬币,m 最大价值
 for(i=1;i<=n;i++)scanf("%d",&a[i]);//每种的面值
for(i=1;i<=n;i++) scanf("%d",&b[i]);//每种的数量
for(i=1;i<=m;i++)f[i]=M;// 背包初始化
 f[0]=0;
 for(j=1;j<=n;j++)//第 j 种硬币
 for(p=1;p<=b[j];p++)//枚举使用第 j 种硬币 p 次【拆成 P 个 1 枚】
 { for(i=m;i>=a[j];i--) //对产生的价值 i 优化
 if(f[i-a[j]]+1<f[i])f[i]=f[i-a[j]]+1;
 }
 for(i=1;i<=m;i++)
 if(f[i]==M)cout<<"-1"<<endl;
 else cout<<f[i]<<endl;
}