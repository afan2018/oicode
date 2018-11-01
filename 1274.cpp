#include<iostream>
using namespace std;
int n,note[2000];
int zs(int n)
{
	int t1=0;
	while(n>0)
	{
		n/=2;
	    t1++;
	}
    return t1-1;
}
void qw(int n)
{
	if(n==0)return;
	if(n==1){cout<<"2(0)";return;}
	if(n==2){cout<<"2";return;}
	if(n==3){cout<<"2+2(0)";return;}
	int re1=zs(n),pa1=1,pa2;
	for(int i=1;i<=re1;i++)pa1*=2;
    pa2=n-pa1;
    cout<<"2(";
    qw(re1);
    cout<<")";
    if(pa2) cout<<"+",qw(pa2);
}
int main(){
	cin>>n;
	qw(n);
	return 0;
}
