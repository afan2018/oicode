#include<iostream>
const int INF=1<<30;
using namespace std;
long long S[205][205]={0},a[205][205]={0},Ai[205]={0},Bi[205]={0},pap,sub;
int main(){
	#ifdef ONLINE_JUDGE
	#else
    freopen("/Users/anthonyfan/Documents/oi/cpp/mat.in","r",stdin);
	freopen("/Users/anthonyfan/Documents/oi/cpp/mat.out","w",stdout);
	#endif
	cin>>pap>>sub;
	for(int i=1;i<=sub;i++)
		cin>>Ai[i]>>Bi[i];
	for(int i=1;i<=sub;i++)
		for(int j=1;j<=pap;j++)
		{
			S[i][j]=INF;
			long long k=1;
			for(int p=1;p<=Bi[i];p++) k*=j;
			a[i][j]=Ai[i]*k;
 		}
 	for(int i=1;i<=pap;i++) S[1][i]=a[1][i];
 	for(int i=2;i<=sub;i++)
 		for(int j=1;j<=pap;j++)
 			for(int k=0;k<=j;k++)
 				S[i][j]=min(S[i][j],S[i-1][j-k]+a[i][k]);
 	cout<<S[sub][pap]<<'\n';
	return 0;
}
