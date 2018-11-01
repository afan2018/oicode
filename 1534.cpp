 #include<iostream>
 #include<iomanip>
 using namespace std;
 int main() 
 {    int m,i;
      double s=0;
      cin>>m;
      for(i=1;s<=m;i++)
      s=s+1/double(i);
      cout<<i-2;
      return 0;
 }