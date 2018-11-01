#include<iostream>
using namespace std;
int main(){
    string str;
    int ten=0,n,i,o=1;
    unsigned long len;
    cin>>n>>str;
    len=str.length();
    for(i=len-1;i>=0;i--)
    {
    	int p=ten;
        if((str[i]>='0')&&(str[i]<='9'))
        {
            ten+=(str[i]-'0')*o;
            o=o*n;
        }
        else
        {
            int c=str[i]-'A'+10;
            ten+=c*o;
            o=o*n;
        }
    }
    cout<<"("<<str<<")"<<n<<"=("<<ten<<")10";
    return 0;
}