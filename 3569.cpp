#include<iostream>
using namespace std;
long long a[500005]={0};
int main(){
	int n,k,l=1,r=1,ans=0,x;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;a[i]=a[i-1]+x;
	}
	while(r<=n)
	{
	  if(a[r]-a[l-1]==k)ans++,l++,r++;
	  else if(a[r]-a[l-1]<k)r++;
	         else l++; 
	}
	cout<<ans;
	return 0;
}
