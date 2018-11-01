#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int a[30001],b[30001],n,w,h,f[100001],v[30001];
void qsort(int L,int r)
{  int i=L,j=r,mid1=b[(L+r)/2],mid2=a[(L+r)/2];
   while (i<=j)
   {  while(b[i]<mid1||(b[i]==mid1&&a[i]<mid2))i++;
      while(b[j]>mid1||(b[j]==mid1&&a[j]>mid2))j--;
      if (i<=j){swap(a[i],a[j]);swap(b[i],b[j]);swap(v[i],v[j]);i++;j--;}
   }  
   if(i<r)qsort(i,r);
   if(j>L)qsort(L,j);
}
int main()
{  int i,j,k,m=0,ma=0;
   cin>>n;
   for(i=1;i<=n;i++){cin>>a[i]>>b[i]>>v[i];m=max(m,b[i]);}
   qsort(1,n);  
   i=1;
   for(j=0;j<=m;j++)
   {  if(ma>f[j])f[j]=ma;
      while(b[i]==j){ f[j]=max(f[j],f[a[i]]+v[i]);i++;}
      if(f[j]>ma)ma=f[j];
   }
   cout<<f[m]<<endl;
   return 0;
}
