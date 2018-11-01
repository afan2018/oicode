 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int a,i;
      cin>>a;
      bool bj=0;
      for(i=2;i<a;i++)
      {
      	if(a%i==0){bj=1;break;}
      }
      if(bj==0) cout<<"YES";
      else cout<<"NO";
      return 0;
 }