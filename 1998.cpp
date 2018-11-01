#include<iostream>
#include<cmath>
using namespace std;
int n,tar,pres;
int Weird_Function(int op,int ed){
	if(op==ed) return op;
	int mid=(op+ed)/2;
	pres=int(mid*log10(mid))+1;
	if(pres<tar) return Weird_Function(mid+1,ed);
	else return Weird_Function(op,mid);
}
int main(){
	cin>>tar;
	cout<<Weird_Function(1,0xfffffff);
	return 0;
}
