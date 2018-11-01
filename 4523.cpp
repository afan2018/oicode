#include<iostream>
using namespace std;
int main(){
	int k,coin=1,day=0,tot=0;
	cin>>k;
	for(int i=1;i<=k;i++){
		tot+=coin;
		day++;
		if(coin==day)coin++,day=0;
	}
	cout<<tot;
	return 0;
}
