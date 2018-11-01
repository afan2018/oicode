#include<iostream>
using namespace std;
int main(){
    int max=0,who=0,n,i,s,bj;
    char sco;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        s=0;bj=0;
        cin>>sco;
        for(;;)
        {   if(sco=='E') break;
            if(sco=='Y') {s++;bj++;}
            if(sco=='N') bj=0;
            if(bj==3) {s++;bj=0;}
            cin>>sco;
        }
        if(s>=max){max=s;who=i;}
    }
    cout<<who<<endl;
    cout<<max<<endl;
    return 0;
}