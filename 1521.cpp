#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{     double b,a;
      cin>>a;
      if (a<=10) cout<<"2.50";
       else cout<<fixed<<setprecision(2)<<2.5+1.5*(a-10);
}