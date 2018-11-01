 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int a,b=0;
      cin>>a;
      while(a>=1)
      {
      	b=b+a%10;
      	a=a/10;
	  }
	  cout<<b;
      return 0;
 }
