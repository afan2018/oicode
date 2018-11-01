#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,seq[100005]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>seq[i];
	sort(seq+1,seq+n+1);
	for(int i=1;i<=n;i++)
	cout<<seq[i]<<' ';
	return 0;
}
