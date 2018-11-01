 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int a,b,r,c,d;
      cin>>a>>b;
	  c=a;
	  d=b;
	  while(b!=0)
      {
      	r=a%b;
      	a=b;
		b=r;
	  }
	  cout<<(c*d)/a;
      return 0;
 }