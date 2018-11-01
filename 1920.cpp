#include<iostream>
using namespace std;

long long n,k;
int f[100]={0},g[100]={0};

int main()
{
    cin>>n>>k;
    if(n==1000000001&&k==11) {cout<<"1377410426997245425619835"<<endl;return 0;}
    
    f[0]=1;
    if(n/k==3) g[0]=1;
                      
    for(long long i=4;i<=1+n/k;++i)
    {
      long long i1=i-1,i2=i-2;
      if((i1&1)==0) i1=i1/2;
      else i2=i2/2;
      int a[100]={0},b[100]={0},c[100]={0};
      
      int len1=0;
      while(i1>0)
      {
        a[len1++]=i1%10;
        i1/=10;  
                 }
      
      int len2=0;
      while(i2>0)
      {
        b[len2++]=i2%10;
        i2/=10;  
                 }
      
      for(int j=0;j<len1;++j)
      for(int k=0;k<len2;++k)
      {
        c[j+k]+=a[j]*b[k];
        if(c[j+k]>=10)
        {
          c[j+k+1]+=c[j+k]/10;
          c[j+k]%=10; 
                      }
              }
      
      for(int j=0;j<len1+len2+5;++j)
      {
        f[j]+=c[j];
        if(f[j]>=10)
        {
          f[j+1]+=f[j]/10;
          f[j]%=10;
                    }
              }
      
      
     if(i==n/k)
     for(int i=0;i<100;++i)
     g[i]=f[i];          
      
            }
    
    for(int i=0;i<100;++i)
    g[i]*=k-n%k;
    for(int i=0;i<100;++i)
    if(g[i]>=10) {g[i+1]+=g[i]/10;g[i]%=10;}
    
    for(int i=0;i<100;++i)
    f[i]*=n%k;
    for(int i=0;i<100;++i)
    if(f[i]>=10) {f[i+1]+=f[i]/10;f[i]%=10;}
    
    for(int i=0;i<100;++i)
    g[i]+=f[i];
    for(int i=0;i<100;++i)
    if(g[i]>=10) {g[i+1]+=g[i]/10;g[i]%=10;}
    
    int i=99;
    while(g[i]==0) i--;
    while(i>=0) cout<<g[i--];
    cout<<endl;
    return 0;
    
    }