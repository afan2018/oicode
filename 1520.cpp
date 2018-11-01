#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{   int a,b,c,d;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if (d>=0) cout<<"YES";
     else cout<<"NO SOLUTION";
    return 0;
}