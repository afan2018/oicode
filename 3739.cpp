#include <iostream>
using namespace std;
long long stack[80080]={0},top=0,n,ans=0;
int main()
{
	cin>>n;
	stack[0]=int(0x7f7f7f7fll);
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		while(stack[top]<=x) top--;
		stack[++top]=x;
		ans+=top-1;
	}
	cout<<ans;
	return 0;
}
