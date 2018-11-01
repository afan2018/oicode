#include<iostream>
using namespace std;
int main(){
	double hen,cock,chick,x,y,z;
	cin>>hen>>cock>>chick;
	for (x=1;x<=100;x++)
	for (y=1;y<=100;y++)
	for (z=1;z<=100;z++)
	if((x+y+z==100)&&(hen*x+cock*y+chick*z==100)) 
    cout<<x<<" "<<y<<" "<<z<<endl;
	return 0;
}