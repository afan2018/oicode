#include<iostream>
using namespace std;
int ds(int a)
{
	int z;
	if(a==0||a==6||a==9)z=6;
    if(a==1)z=2;
    if(a==2||a==5||a==3)z=5;
    if(a==4)z=4;
    if(a==7)z=3;
    if(a==8)z=7;
    return z;
}
	
int main(){
	int a,b,c,m,num=0,z,y,re,tot,gs[2222]={0};
	for(int i=0;i<=2222;i++)
	{
		int a1,a2,a3,a4,a11,a22,a33,a44;
		a1=i/1000;
		a2=i/100%10;
		a3=i/10%10;
		a4=i%10;
	    a11=ds(a1);
	    a22=ds(a2);
	    a33=ds(a3);
	    a44=ds(a4);
		if(a1==0&&a2!=0)a11=0;
		if(a2==0&&a1==0&&a3!=0)a11=0,a22=0;
		if(a3==0&&a2==0&&a1==0&&a4!=0)
		{
			a11=0;a22=0;a33=0;
		}
		if(a4==0&&a3==0&&a1==0&&a2==0)
		{
			a11=0;a22=0;a33=0;a44=6;
		}
	    gs[i]=a11+a22+a33+a44;
	}
	cin>>m;
	for(a=0;a<=1111;a++)
	  for(b=0;b<=1111;b++)
	    {
	    	c=a+b;
	    	z=gs[a];
	    	y=gs[b];
	    	re=gs[c];
	    	tot=z+y+re+4;
	    	if(tot==m)num++;
		}
	cout<<num;
	return 0;
}
