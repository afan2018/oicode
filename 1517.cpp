#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{     int a,b,c;
      double d,s;
      cin>>a>>b>>c;
      d=double(a+b+c)*1.0000/2;
      s=sqrt((d)*(d-a)*(d-b)*(d-c));
      cout<<fixed<<setprecision(2)<<s;
      return 0;
}
