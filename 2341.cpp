#include<iostream>
using namespace std;
int main()
{  int i,n,sa,sb,a[201];
   cin>>n;
   for(i=1;i<=2*n;i++)cin>>a[i];
   sa=0;sb=0;
   for(i=1;i<=n;i++){sa=sa+a[2*i-1];sb=sb+a[2*i];}
   if(sa!=sb)cout<<"yes"<<endl;else cout<<"no"<<endl;
   return 0;
}
/*
#include<iostream>
using namespace std;
int main()
{  int i,n,sa,sb,a[201];
   cin>>n;
   for(i=1;i<=2*n;i++)cin>>a[i];
   sa=0;sb=0;
   for(i=1;i<=n;i++){sa=sa+a[2*i-1];sb=sb+a[2*i];}
   if(sa!=sb)cout<<"yes"<<endl;else cout<<"no"<<endl;
   return 0;
}
*/