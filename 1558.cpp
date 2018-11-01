#include<iostream>
using namespace std;
int main(){
	int a[105],n,x;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x)
		{
			for(int j=i;j<=n;j++)a[j]=a[j+1];
			n--;
			break;
		}
	    else if(a[i]>x)
	    {
			for(int j=n+1;j>=i+1;j--) a[j]=a[j-1];
			a[i]=x;n++;
			break;
		}
	}
	if(a[n]<x)a[++n]=x;
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}
