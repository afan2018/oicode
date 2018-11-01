#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int s[30]={0},maxx=-1,minn=233,len,i,bj=0;
	string a;
	cin>>a;
	len=a.length();
	for(i=0;i<len;i++)
	   s[a[i]-96]++;
	for(i=1;i<=26;i++)
	  {if(s[i])	 
	     {	  
	     if(s[i]>maxx)maxx=s[i];
	     if(s[i]<minn)minn=s[i];
	     }
      }
	int k=maxx-minn;
	if(k==2)bj=1;
	else for(i=2;i<=k-1;i++)
	      {
	   		if(k%i!=0)
	          {
			   	if(i==k-1)
				   bj=1;	       		   
	       		else continue;
			  }
			  
	       	else
		      {
		  	   bj=0;break;
		      }
	   	  } 
	if(bj==1)cout<<"Lucky Word"<<endl<<k;
	else cout<<"No Answer\n0";  
	     

}