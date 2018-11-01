#include<iostream>
#include<cstdlib>
using namespace std;
int n,num[25]={0},lim[25]={0},tar,sol=0;
bool f=0;
void array(int tr)
{
	if(f)return;
	if(tr==n+1)
	{
		sol++;
		if(sol==tar){
			for(int i=1;i<=n;i++)
				cout<<num[i]<<' ';
		f=1;
		return;
		}
			
	}
	else for(int i=1;i<=n;i++)
		if(!lim[i]){
			num[tr]=i;
			lim[i]=1;
			array(tr+1);
			lim[i]=0; 
		} 
}
int main(){
	cin>>n>>tar;
	array(1);
	return 0;
}
