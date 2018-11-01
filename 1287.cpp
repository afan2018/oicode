#include<iostream>
using namespace std;
string str;
int n,tmp[25]={0},cnt=0,fr=0,to=0,idx=1,pos=0,fl=0;
int main()
{
    cin>>str;
    int i;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='<') {fl=1;continue;}
        if(fl&&str[i]!='>') tmp[++cnt]=str[i]-'0';
        else if(fl) {pos=i+1;break;}
    }
    for(int j=cnt;j>=1;j--)
        fr+=tmp[j]*idx,idx*=10;
    cnt=0,idx=1;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!='<') tmp[++cnt]=str[i]-'0';
        else break;
    }
    for(int j=cnt;j>=1;j--)
        n+=tmp[j]*idx,idx*=fr;
    cnt=0,idx=1;
    for(int i=pos;i<str.length();i++)
        tmp[++cnt]=str[i]-'0';
    for(int j=cnt;j>=1;j--)
        to+=tmp[j]*idx,idx*=10;
    cnt=0,idx=1;
    while(n)
    {
        tmp[++cnt]=n%to;
        n/=to;
    }
    for(int i=cnt;i>=1;i--)
        cout<<tmp[i];
    return 0;
}
