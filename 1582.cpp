#include<iostream>
using namespace std;
int line,n,raw[10]={0},att[3][25]={0},sol=0;
void nqueen(int line)
{
	if(line>n)
	{
		sol++;
		for(int i=1;i<=n;i++)
			cout<<raw[i]<<' ';
		cout<<endl;
		return;
	}
	else for(int i=1;i<=n;i++)
		{
			if(!att[0][i]&&!att[1][line+i]&&!att[2][line-i+n])
			{
				raw[line]=i;
				att[0][i]=1,att[1][line+i]=1,att[2][line-i+n]=1;
				nqueen(line+1);
				att[0][i]=0,att[1][line+i]=0,att[2][line-i+n]=0;
			}
		}
}
int main()
{
	cin>>n;
	nqueen(1);
	if(sol==0)cout<<"no solute!";
	return 0;
}
