#include <iostream>
using namespace std;
int main()
{
	int k;
	double sum=0;
	cin>>k;
	for(int i=1;;i++)
	{
		sum+=double(1.0/i);
		if(sum>k) {cout<<i;return 0;}
	}
}