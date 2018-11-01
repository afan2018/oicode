#include<iostream>
using namespace std;
int main(){
    int n,m,t=1,f=1,sum;
    cin>>n>>m;
    sum=f*(m-1);
    while(t<=n)
    {    if(sum%(m-1)!=0)
    {    t=1;
        f++;
        sum=f*(m-1);
    }
        sum=sum*m/(m-1)+1;
        t++;
    }
    cout<<f*(m-1)<<endl<<sum;
    return 0;
}