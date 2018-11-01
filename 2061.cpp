#include<iostream>
using namespace std;
int hh=0,month[]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans[10]={0},n,year=0,last=0,lim=0,now=0;
int main()
{
    cin>>n;
    ans[6]=1;
    last=6;
    while(year<n)
    {
        now=1900+year;
        for(int i=1;i<=12;i++)
        {
            if(year==0&&i==1) i++;
            if(i==1) lim=31;
            else lim=month[i-1];
            if(((now%100==0&&now%400==0)||(now%100!=0&&now%4==0))&&i==3) lim++;
            hh=(last+lim%7)%7;
            if(hh==0) hh=7;
            ans[hh]++;
            last=hh;
        }
        year++;
    }
    cout<<ans[6]<<' '<<ans[7]<<' ';
    for(int i=1;i<=5;i++)
        cout<<ans[i]<<' ';
    return 0;
}
