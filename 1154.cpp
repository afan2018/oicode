#include<iostream>
using namespace std;
int main(){
	string str;
	int h[30]={0};
	cin>>str;
	int len=str.length();
	len--;
	for(int i=0;i<len;i++)
		h[str[i]-'a']++;
	for(int i=0;i<27;i++)
		if(h[i])cout<<char(i+'a')<<':'<<h[i]<<endl;
	return 0;
}
