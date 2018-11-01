#include<cstring>
#include<iostream>
using namespace std;
int n,f[20]={0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		cin>>n; 
		n--;
		int i=0;
		while(1)
		{
			i++;
			f[i]=f[i-1]*3;
			if(n>f[i]) n-=f[i];
			else break;
		}
		while(i--)
		{
			if(n/f[i]==0) cout<<2;
			else if(n/f[i]==1) cout<<3;
			else cout<<7;
			n%=f[i];
		}
		cout<<endl;
	}
	return 0;
}