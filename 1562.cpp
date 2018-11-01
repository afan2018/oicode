#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int x,i;
	int a[25][6]={0};
	double n[25];
	cin>>x;
	for(i=1;i<=x;i++)
	{
	  for(int o=1;o<=3;o++)
	  cin>>a[i][o];
	}
    
    	for(int s=1;s<=x;s++)
    	{
    	  n[s]=double(a[s][1]+a[s][2]+a[s][3])/3;
		}
	
	for(int f=1;f<=x;f++)
	cout<<fixed<<setprecision(2)<<n[f]<<" ";
	return 0;
}
/*
3
50 55 60
60 65 70
70 75 80
*/