#include<iostream>
using namespace std;
int main(){
    int atlast=1,day,rest,whichday;
    cin>>day;
    for(whichday=1;whichday<=day;whichday++)
    {
        if(whichday==1) {
            atlast=1;continue;
        }
        else rest=atlast*2+2;
        atlast=rest;
    }
    cout<<atlast;
    return 0;
}