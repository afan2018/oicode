#include<iostream>
#include<cstring>
using namespace std;
void init(int a[])
{
	string s;
	cin>>s;
	a[0]=s.length();
	for(int i=1;i<=a[0];i++)
	a[i]=s[a[0]-i]-'0';
}
int compare(int a[],int b[])
{
	if(a[0]>b[0])return 1;
	if(a[0]<b[0])return -1;
	for(int i=a[0];i>=1;i--)
	{
		if(a[i]>b[i])return 1;
		if(a[i]<b[i])return -1;
	}
	return 0;
}
void jian(int a[],int b[])
{
	for(int i=1;i<=a[0];i++)
	{
		if(a[i]<b[i]){
			a[i+1]--;a[i]+=10;
		}
		a[i]=a[i]-b[i];
	}
	while(a[0]>0&&a[a[0]]==0)a[0]--;
}
void print(int a[])
{
	int i;
	if(a[0]==0){cout<<"0";return;}
	for(i=a[0];i>=1;i--)
	cout<<a[i];
}
void numcpy(int p[],int q[],int det)
{
	for(int i=1;i<=p[0];i++)
	q[i+det-1]=p[i];
	q[0]=p[0]+det-1;
}
void chugao(int a[],int b[],int c[])
{
	int i,tmp[101];
	c[0]=a[0]-b[0]+1;
	for(i=c[0];i>=1;i--)
	{
		memset(tmp,0,sizeof(tmp));
		numcpy(b,tmp,i);
		while(compare(a,tmp)>=0)
		{
			c[i]++;jian(a,tmp);
		}
	}
	while(c[0]>0&&c[c[0]]==0)c[0]--;
}
int main(){
	int a[105]={0},b[105]={0},c[105]={0};
	init(a);
	init(b);
	chugao(a,b,c);
	print(c);
	cout<<"\n";
	print(a);
	return 0;
}
