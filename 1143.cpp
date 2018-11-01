 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int b,c,d;
      for(int i=1000;i<=9999;i++) 
	  {
	  b=i%100;
      c=i/100;
      d=(b+c)*(b+c);
	  if (d==i) cout<<i<<" ";
      }
      return 0;
 }