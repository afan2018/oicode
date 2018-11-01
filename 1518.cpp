#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{   int x,y;
    cin>>x;
    if (x>0) y=x+1;
     else if (x==0) y=0;
      else y=x-1;
    cout<<y;
}
