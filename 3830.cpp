#include <iostream>
using namespace std;
int a,b,cnt=0;
void c(int x)
{
	while(x)
	{
		int hh=x%10;
		if(hh==b) cnt++;
		x/=10;
	}
	return;
}
int main()
{
	cin>>a>>b;
	for(int i=1;i<=a;i++)
		c(i);
	cout<<cnt<<'\n';
	return 0;
}