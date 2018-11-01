#include<iostream>
#include<cstring>
using namespace std;
char s[200],g[100][100];
string b[6];
int f[1000][6]={0},n1;
bool cmp(int x,int e,int j)
{
	int i;
	for(i=0;i<b[j].length();i++)
		if(x+i>e||s[x+i]!=b[j][i])return false;
	return true;
}
int word(int x,int e)
{
	int i,j,c=0;
	for(i=x;i<=e;i++)
		for(j=0;j<n1;j++) 
			if(cmp(i,e,j))
				{c++;break;}
	return c;
}
int main()
{    
	int n,k,i,j,w,max;
	cin>>n>>k;
	n*=20;
	for(i=1;i<=n;i++)cin>>s[i];
	cin>>n1;
	for(i=0;i<n1;i++)cin>>b[i];
	for(i=1;i<=k;i++)
		for(j=i;j<=n-k+i;j++)
		{
			max=0;
			for(w=i-1;w<=j-1;w++)
				if(max<f[w][i-1]+word(w+1,j))max=f[w][i-1]+word(w+1,j);
			f[j][i]=max;
		}
	cout<<f[n][k];
}
