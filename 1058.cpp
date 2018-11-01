#include<iostream>
using namespace std;
int use[15]={0},tmp=0,save=0;
int main()
{
    for(int i=1;i<=12;i++)
        cin>>use[i];
    for(int i=1;i<=12;i++)
    {
        tmp+=300;
        if(tmp<use[i]) {cout<<'-'<<i<<endl;return 0;}
        if((tmp-use[i])/100)
        {
            int minus=((tmp-use[i])/100)*100;
            tmp-=minus;
            save+=minus;
        }
        tmp-=use[i];
    }
    cout<<save*1.2+tmp<<endl;
    return 0;
}
