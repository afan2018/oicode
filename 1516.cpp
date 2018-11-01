#include <iostream>
using namespace std;
int main()
{     int a,b,c,d,e,x,y;
      cin>>x;
      a=x/1000;
      b=x/100%10;
      c=x/10%10;
      e=x%10;
      y=e*1000+c*100+b*10+a;
      cout<<y<<endl;
      return 0;
}