#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int lim=0,val[30005]={0},n,head,tail;
	cin>>lim>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	sort(val+1,val+n+1);
	head=1,tail=n;
	int sum=0;
	while(head<tail)
	{
		if(val[head]+val[tail]<=lim)head++,tail--;
			else tail--;
		sum++;
	}
	if(head==tail)sum++;
	cout<<sum;
	return 0;
}
