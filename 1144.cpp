 #include <iostream>
 #include <iomanip>
 using namespace std;
 int main() 
 {    char a;
      int sum=0;
	  while (1)
	  {
	    cin>>a;
	    if(a=='#') break;
		if(a=='a'||a=='A') sum++;
	  }
	  cout<<sum;
      return 0;
 }
