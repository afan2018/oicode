#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[20][20],b[20][20],i,j,n;
cin>>n;
for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
         cin>>a[i][j];      
for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
            b[j][i]=a[i][j];  
for(i=1;i<=n;i++)       
{
      for(j=1;j<=n;j++)cout<<b[i][j]<<" ";
      cout<<endl;
}

	return 0;
}
