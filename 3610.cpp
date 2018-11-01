#include<iostream>
using namespace std;
int n;
int main()
{
    while(cin>>n)
    {
        int sum=0;
        while(n)
        {
            n/=5;
            sum+=n;
        }
        cout<<sum<<endl;
    }
    return 0;
}