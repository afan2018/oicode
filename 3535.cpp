#include<iostream>
#include<cmath>
using namespace std;
bool c(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}
int n,ans;
int main()
{
    cin>>n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(c(i)&&n%i==0)
        {
            ans=i;
            int tmp=n/i;
            ans=max(ans,tmp);
            break;
        }
    }
    cout<<ans;
    return 0;
}
