#include<iostream>
#include<iomanip>
using namespace std;
double h,dis[205]={0},hi[205]={0},ans=0;
int n;
int main()
{
	cin>>h>>n;
	for(int i=1;i<=n;i++)
		cin>>hi[i]>>dis[i];
	for(int i=1;i<=n;i++)
	{
		ans+=dis[i];
		if(hi[i]>=h) {cout<<fixed<<setprecision(1)<<ans;break;}
	}
	return 0;
}