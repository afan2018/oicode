#include<iostream>
using namespace std;
int n,m,k,j,i,x,y;
int main()
{  while(cin>>x)
   {  if(x%12==0)cout<<"YES"<<endl;
        else{  if(x%4==0)cout<<3<<endl;
                 else if(x%6==0)cout<<4<<endl;
                        else cout<<"NO"<<endl;
            }
   }
}
