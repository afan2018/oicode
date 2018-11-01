#include<iostream>
using namespace std;
double n;
int main()
{
    cin>>n;
    int l=int(n);
    double r=n-l;
    int tmp[105]={0},cnt=0;
    while(l)
    {
        tmp[++cnt]=l%2;
        l/=2;
    }
    for(int i=cnt;i>=1;i--)
        cout<<tmp[i];
    cout<<'.';
    cnt=0;
    while(1)
    {
        if(r==0||cnt>=20) break;
        r*=2;
        cout<<int(r);
        cnt++;
        r=r-int(r);
    }
	return 0;
}
