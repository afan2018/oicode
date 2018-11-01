#include<iostream>
using namespace std;
int n,l=1,r=1,sum=1;
int main()
{
    cin>>n;
    while(l<=r)
    {
        if(sum<=n) sum+=++r;
        if(sum>n) sum-=l++;
        if(sum==n&&(l!=n)) cout<<l<<' '<<r<<endl;
    }
    return 0;
}
