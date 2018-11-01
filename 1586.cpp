#include<iostream>
#define max_size 255
using namespace std;
int main(){
	int flag=0;
	while(1)
	{
		char ch;
		cin>>ch;
		if(ch=='@')break;
		if(ch=='(')flag++;
		else if(ch==')')flag--;
		if(flag<0){
			cout<<"NO";
			return 0;
		}
	}
	if(!flag)cout<<"YES";
	else cout<<"NO";
	return 0;
}
