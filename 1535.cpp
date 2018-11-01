#include<iostream>
using namespace std;
int main(){
    int i,a,b,c,d,num=64;
    cin>>a;
    for(i=1;i<=a;i++)
    {   for(b=i;b<=(a-1);b++)
            cout<<" ";
        for(c=1;c<=i;c++)
            cout<<char(num+c);
        for(d=i-1;d>0;d--)
            cout<<char(num+d);
    cout<<endl;
    }
    return 0;
}