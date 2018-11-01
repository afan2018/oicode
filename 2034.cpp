#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
double sx[20005]={0},sy[20005]={0},n,sumx=0,sumy=0;
double ansx,ansy;
int main()
{
	srand(233333333);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&sx[i],&sy[i]);
		sumx+=sx[i],sumy+=sy[i];
	}
	ansx=(double)sumx*1.0/n;
	ansy=(double)sumy*1.0/n;
	int ti=pow(n,3.0/4),pos;
	for(int i=1;i<=ti;i++)
	{
		pos=rand()%int(n)+1;
		for(int j=1;j<=n+1;j++)
		{
			if(sx[pos]+sx[j]==ansx*2&&sy[pos]+sy[j]==ansy*2) break;
			if(j==n+1) {cout<<"This is a dangerous situation.";return 0;} 
		}
	}
	cout<<"V.I.P. should stay at ("<<fixed<<setprecision(1)<<ansx<<','<<ansy<<").";
	return 0;
}
