#include<iostream>
#include<cstdio>
using namespace std;
int seq[1025]={0},n,tms=1;
char root;
void FBI(int x,int y)
{
	if(x==y)
	{
		if(seq[x]==1)cout<<'I';
  		        else cout<<'B';
		return;
	} 
	FBI(x,x+(y-x+1)/2-1);
	FBI(x+(y-x+1)/2,y);
	bool marki=false,markb=false;
	for(int i=x;i<=y;i++)
	{
		if(seq[i]==0)markb=true;
		else marki=true;
	}
	if(marki&&markb) root='F';
	else 
	{
		if(marki) root='I';
		if(markb) root='B';
	}
	cout<<root;
	return;
}
int main(){
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++) tms*=2;
	for(int i=1;i<=tms;i++) seq[i]=(getchar()-'0');
	FBI(1,tms);
	return 0;
}
/*
3
10001011
*/