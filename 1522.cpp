#include<iostream>
using namespace std;
int main(){
	int sco;
	cin>>sco;
	if(sco>=86)cout<<"VERY GOOD";
	if(sco<86&&sco>=60)cout<<"GOOD";
	if(sco<60)cout<<"BAD";
	return 0;
}
