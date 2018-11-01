 #include <iostream>
 #include <iomanip>
 using namespace std;
 int main() 
 {    double  a,b=0,max=0,min=11,c;
      for (int i=0;i<=9;i++)
	  {
      cin>>a;
	  b=b+a;
	  if(a>max) max=a;
	  if(a<min) min=a;
	  }
	  b=b-max-min;
	  c=b/8;
	  cout<<fixed<<setprecision(2)<<c;
      return 0;
 }
