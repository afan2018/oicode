#include<iostream>
using namespace std;
int main()
{   int a[55]={0,1,1,1},i,n;
    cin>>n;
    if(n<4)cout<<1<<endl;
    else {   for(i=4;i<=n;i++)a[i]=a[i-1]+a[i-3];
        cout<<a[n]<<endl;
    }
    return 0;
}