#include<iostream>
using namespace std;
void init(int a[])
{
    string s;
    cin>>s;
    a[0]=s.length();
    for(int i=1;i<=a[0];i++)
    {
        if(s[a[0]-i]>'9'){a[i]=s[a[0]-i]-'A'+10;continue;}
        a[i]=s[a[0]-i]-'0';
    }
}
bool compare(int a[],int b[])
{
    for(int i=1;i<=a[0];i++)
        if(a[i]!=b[i]) return false;
    return true;
}
void daoxu(int a[],int b[])
{
    for(int i=a[0];i>=1;i--)
        b[a[0]-i+1]=a[i];
}
void jiagao(int a[],int b[],int n)
{
    if(a[0]<b[0])a[0]=b[0];
    for(int i=1;i<=a[0];i++)
        a[i]+=b[i];
    for(int i=1;i<=a[0];i++)
    {
        a[i+1]+=a[i]/n;
        a[i]%=n;
    }
    while(a[0]>0&&a[a[0]+1]>0)a[0]++;
}
void print(int a[])
{  int i;
    if(a[0]==0){cout<<0<<endl;return;}
    for(i=a[0];i>0;i--)cout<<a[i];cout<<endl;
}
int main(){
    int a[105]={0},z[105]={0},c[105]={0},n,bj=0;
    cin>>n;
    init(a);
    for(int i=1;i<=30;i++)
    {
        daoxu(a,z);
        jiagao(a,z,n);
        daoxu(a,c);
        if(compare(a,c)){
            cout<<i<<endl;bj=1;break;
        }
    }
    if(bj==0)cout<<"Impossible"<<endl;
    return 0;
}
