 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int a,b,max=0;
      cin>>a;
      for(int i=1;i<=a;i++)
      {
	  cin>>b;
      if(b>max) max=b;
	  }
	  cout<<max;
      return 0;
 }