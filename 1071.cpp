#include<iostream>
using namespace std;
int len,k,ans[10000]= {0},map[100][1000]= {0},a[1005]= {0};
string str;
void Cheng(int a[],int k)
{
	for(int i=1; i<=a[0]; i++)a[i]*=k;
	for(int i=1; i<=a[0]; i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]+1]>0)
	{
		a[0]++;
		a[a[0]+1]+=a[a[0]]/10;
		a[a[0]]=a[a[0]]%10;
	}
}
void Print(int a[]) 
{
	if(a[0]==0)
	{
		cout<<0<<endl;
		return;
	}
	for(int i=a[0]; i>=1; i--)cout<<a[i];
	cout<<endl;
}
void Close()
{
	int i,j,k;
	for(k=0; k<=9; k++)
		for(i=0; i<=9; i++)
			for(j=0; j<=9; j++)
				map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
}
void Count()
{
	int i,j;
	for(i=0; i<=9; i++)
		for(j=0; j<=9; j++)
			a[i]+=int(map[i][j]);
	for(i=0; i<len; i++)
		Cheng(ans,a[str[i]-'0']);
	Print(ans);
}
int main()
{
	int x,y;
	ans[0]=ans[1]=1;
	cin>>str>>k;
	len=str.length();
	for(int i=0; i<len
	; i++)
	map[str[i]-'0'][str[i]-'0']=1;
	for(int i=1; i<=k; i++)
	{
		cin>>x>>y;
		map[x][y]=1;
	}
	Close();
	Count();
}
