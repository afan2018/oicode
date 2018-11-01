#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,seq[105]={0},cnt=0,seqq[105];
    cin>>a;
    for(int i=1;i<=a;i++)
        cin>>seq[i];
    sort(seq+1,seq+a+1);
    for(int i=1;i<=a;i++)
    {
        if(seq[i]==seq[i+1])continue;
        else seqq[++cnt]=seq[i];
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
        cout<<seqq[i]<<' ';
    cout<<endl;
    return 0;
}
