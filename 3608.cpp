#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,tot;
int main(){
	while(cin>>a>>b)
	{
		tot=__gcd(a,b);
		cout<<a*b/tot<<endl;
	}
	return 0;
}
