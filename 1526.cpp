#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string num;
	int water[1005]={0};
	cin>>num;
	int len=num.length();
	for(int i=0;i<len;i++)
		water[i]=num[i]-'0';
	sort(water,water+len);
	for(int i=len-1;i>=0;i--)
		cout<<water[i];
	return 0;
}
