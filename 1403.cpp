#include<iostream>
using namespace std;
int n,bomb[10005]={0},seq[10005]={0},sol=0;
bool Judge(int sit)
{
	if(sit==1)return 1;
	if(sit==2)
	{
		if(seq[1]+seq[2]==bomb[1])return 1;
		return 0;
	}
	if(seq[sit-2]+seq[sit-1]+seq[sit]==bomb[sit-1])return 1;
													else return 0;
}
void Scan_Bomb(int sit)
{
	if(sit==n+1)
	{
		if(seq[n]+seq[n-1]==bomb[n])sol++;
		return;
	}
	for(int i=0;i<=1;i++)
	{
		seq[sit]=i;
		if(Judge(sit))Scan_Bomb(sit+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>bomb[i];
	Scan_Bomb(1);
	cout<<sol;
	return 0;
}