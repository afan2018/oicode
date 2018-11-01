#include<iostream>
using namespace std;
int n,num[10]={0},lim[10]={0};
void array(int tr)
{
	if(tr==n+1)
	{
		for(int i=1;i<=n;i++)cout<<num[i]<<' ';
		cout<<endl;
		return;
	}
	else for(int i=1;i<=n;i++)
	{
		if(!lim[i]){
			num[tr]=i;
			lim[i]=1;
			array(tr+1);
			lim[i]=0; 
		} 
	}
}
int main(){
	cin>>n;
	array(1);
	return 0;
}
