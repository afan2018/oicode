#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll n;
bool c(ll x)
{
    for(ll i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}
int main()
{
    cin>>n;
    for(ll i=2;i<=sqrt(n);i++)
        if(n%i==0&&c(i))
            if(c(n/i))
            {
                puts("It's a MaoLaoDa number.");
                return 0;
            }
    puts("It's not a MaoLaoDa number.");
    return 0;
}
