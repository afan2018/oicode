#include<iostream>
using namespace std;
int main(){
	char a,b;
	cin>>a>>b;
	if((a=='S'&&b=='S')||(a=='R'&&b=='R')||(a=='P'&&b=='P'))cout<<"Equ";
	else if((a=='S'&&b=='R')||(a=='R'&&b=='P')||(a=='P'&&b=='S'))cout<<"Fall";
	else cout<<"Win";
	return 0;
}
