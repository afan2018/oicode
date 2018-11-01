#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{   
    int y,m,feb;
    cin>>y>>m;
	if ((y%400==0&&y!=2200)||((y%4==0)&&(y%400!=0))) feb=29;
	 else feb=28;
	if(m%2==1&&m!=8&&m!=2) cout<<30;
	if(m%2==0&&m!=8&&m!=2) cout<<31;
    if(m==2) cout<<feb;
    if(m==8) cout<<31;
	return 0;
}
