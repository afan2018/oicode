#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[5];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    cout<<a[3]<<' '<<a[2]<<' '<<a[1];
    return 0;
}