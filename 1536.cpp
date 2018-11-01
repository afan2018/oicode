 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int n,m=0,i;
      cin>>n;
	  for(i=1;i<=n;i++)
	  {if(i%7==0) m=m+i;}
	  cout<<m;
      return 0;
 }