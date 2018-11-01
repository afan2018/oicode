#include<iostream>
using namespace std;
int n,a[105]={0},cnt=0;
int main()
{
    cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=2;i<n;i++)
        if((a[i-1]<a[i])&&(a[i+1]<a[i])||(a[i-1]>a[i])&&(a[i+1]>a[i]))
            cnt++;
	cout<<cnt+1;
	return 0;
}
