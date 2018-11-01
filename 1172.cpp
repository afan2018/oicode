#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string str[105];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>str[i];
	sort(str+1,str+n+1);
	for(int i=1;i<=n;i++)
		cout<<str[i]<<endl;
	return 0;
}
