#include<iostream>
using namespace std;
int unh,pos=100,delta=0;
int main()
{
    for(int i=1,x,y;i<=7;i++)
    {
        cin>>x>>y;
        unh=x+y;
        if(unh>8)
        {
            pos=min(pos,i);
            if(unh-8>delta)
            {
                delta=unh-8;
                pos=i;
            }
        }
    }
    cout<<pos<<endl;
    return 0;
}
