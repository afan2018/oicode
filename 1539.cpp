#include <iostream>
using namespace std;
int main(){
    long long  n,i,f[65]={0};
    f[1]=0;f[2]=1;
    cin>>n;
    for(i=3;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    cout<<f[n]<<endl;
    return 0;
}