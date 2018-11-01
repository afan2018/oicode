#include<iostream>
using namespace std;
string comet,group;
int num1=1,num2=1;
int main()
{
    cin>>comet>>group;
    for(int i=0;i<comet.length();i++)
        num1*=comet[i]-'A'+1;
    for(int i=0;i<group.length();i++)
        num2*=group[i]-'A'+1;
    if(num1%47==num2%47) puts("GO");
    else puts("STAY");
    return 0;
}
