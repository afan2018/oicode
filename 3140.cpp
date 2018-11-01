#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int sco,pur,win,flag;}team[15];
int n,ncn,hhh=0,rank=0;
string sha[15];
char ch;
bool cmp(node a,node b)
{
	if(a.sco>b.sco) return true;
	if(a.sco<b.sco) return false;
	if(a.sco==b.sco)
	{
		if(a.pur>b.pur) return true;
		if(a.pur<b.pur) return false;
		if(a.pur==b.pur)
		{
			if(a.win>b.win) return true;
			if(a.win<b.win) return false;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sha[i];
		if(sha[i]=="China") team[i].flag=1;
	}
	for(int i=1;i<=(n-1)*2*(n/2);i++)
	{
		string ta,tb;
		int sco1,sco2,na,nb;
		cin>>ta;
		for(int i=1;i<=n;i++)
			if(ta==sha[i]) 
			{
				na=i;
				cin>>sco1;
				team[na].win+=sco1;
				break;
			} 
		getchar();
		getchar();
		cin>>sco2>>tb;
		for(int i=1;i<=n;i++)
			if(tb==sha[i])
			{
				nb=i;
				team[nb].win+=sco2;
				break;
			}
		if((sco1>sco2)&&(sco1!=sco2)) team[na].sco+=3;
		else if((sco1<sco2)&&(sco1!=sco2)) team[nb].sco+=3;
		if(sco1==sco2) team[na].sco+=1,team[nb].sco+=1;
		team[na].pur+=sco1-sco2;
		team[nb].pur+=sco2-sco1;
	}
	cin>>ch;
	sort(team+1,team+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(team[i].flag) 
		{
			if(i==3)
			{
				if(ch=='Y') hhh=1,rank=i;
				else hhh=0,rank=i;
				break;
			}
			if(i<=2) hhh=1,rank=i;
			else hhh=0,rank=i;
			break;
		}
	}
	cout<<rank<<endl;
	if(hhh) cout<<"Brazil, we are coming!";
	else cout<<"Go home, China Team!";
	return 0;
}