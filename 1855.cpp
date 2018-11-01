#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[3][3]={0},b[3][3]={0},c[3][3]={0},d[23333]={0};
void Mul_matrix(ll m[][3],ll n[][3])
{
	ll i,j;
	c[1][1]=(m[1][1]*n[1][1]%1729+m[1][2]*n[2][1]%1729)%1729;
	c[1][2]=(m[1][1]*n[1][2]%1729+m[1][2]*n[2][2]%1729)%1729;
	c[2][1]=(m[2][1]*n[1][1]%1729+m[2][2]*n[2][1]%1729)%1729;
	c[2][2]=(m[2][1]*n[1][2]%1729+m[2][2]*n[2][2]%1729)%1729;
	memcpy(m,c,sizeof(c));
}
int main()
{
 	ll n;
 	while(cin>>n)
 	{
 		memset(c,0,sizeof(c));
 		memset(a,0,sizeof(a));
 		memset(b,0,sizeof(b));
 		memset(d,0,sizeof(d));
 		if(n<=2){cout<<1<<endl;continue;}
 		n=n-2;
 		while(n>0){d[++d[0]]=n%2;n/=2;}
 		a[1][1]=1;a[1][2]=1;a[2][1]=1;a[2][2]=0;
 		b[1][1]=1;b[1][2]=1;b[2][1]=1;b[2][2]=0;
 		for(ll i=d[0]-1;i>=1;i--)
 		{
	 		 Mul_matrix(a,a);
			 if(d[i]==1)Mul_matrix(a,b);
		}
		ll ans=(a[1][1]+a[2][1])%1729;
		cout<<ans<<endl;
	}
 	
	return 0;
}