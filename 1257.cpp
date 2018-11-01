#include<iostream>
using namespace std;
int n,k,ans=0,a[100]={0};
void Divide_Num(int num)
{
	if(n==0)return;
	if(num==k){if(n>=a[num-1])ans++;return;}
	for(int i=a[num-1];i<=n/(k-num);i++)
	{
		a[num]=i;
		n-=i;
		Divide_Num(num+1);
		n+=i;
	}
}
int main(){
	cin>>n>>k;
	a[0]=1;
	Divide_Num(1);
	cout<<ans;
	return 0;
}
