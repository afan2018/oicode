 #include <iostream>
 #include <iomanip>
 using namespace std;
 int main() 
 {    int a,b,c=0;
      cin>>a;
	  for (b=1;b<=a;b++)
      {
	  if(a%b==0) c=c+b;
	  }
	  cout<<c;
      return 0;
 }