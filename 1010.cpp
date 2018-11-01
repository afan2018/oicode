#include<iostream>
#include<cstring>
using namespace std;
char a[20],b[20];
int len=0;
void f(char a[],char b[],int ll)
{
    int i=0;
    cout<<b[ll-1];
    while(a[i]!=b[ll-1])i++;
    if(i>0)f(a,b,i);
    if(i<ll-1)f(a+i+1,b+i,ll-1-i);
}
int main()
{
    cin>>a>>b;
    len=strlen(b);
    f(a,b,len);
    return 0;
}
