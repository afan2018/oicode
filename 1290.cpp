#include<iostream>
using namespace std;
int main(){
	int a[1005]={0},c1,c2,c3,c4,c5,c6,sum=0,num=0;
	cin>>c1>>c2>>c3>>c4>>c5>>c6;
	for(int b1=0;b1<=c1;b1++)
	  for(int b2=0;b2<=c2;b2++)
	    for(int b3=0;b3<=c3;b3++)
	      for(int b4=0;b4<=c4;b4++)
	        for(int b5=0;b5<=c5;b5++)
	          for(int b6=0;b6<=c6;b6++)
	            {
	          	  sum=b1*1+b2*2+b3*3+b4*5+b5*10+b6*20;
	          	  a[sum]=1;
			    }
	for(int i=1;i<=1000;i++)
	if(a[i])num++;
	cout<<"TOTAL="<<num;
	return 0;
}
