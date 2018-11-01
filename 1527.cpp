#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<100)cout<<10;
    if((n>=100)&&(n<110))cout<<30;
    if((n>=110)&&(n<120))cout<<50;
    if((n>=120)&&(n<130))cout<<70;
    if(n>=130)cout<<80;
    return 0;
}