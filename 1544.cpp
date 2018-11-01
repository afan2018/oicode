#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,ans=0,num[15]={0},two[20]={0},flag=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int pro=i,pro2=i,m=0,mm=0,flag=0;
		memset(num,0,sizeof(num));
		memset(two,0,sizeof(two));
		while(pro!=0)
		{
			num[++m]=pro%10;
			pro/=10;
		}
		for(int i=1;i<=m;i++)
		{
			if(num[i]!=num[m-i+1]){
				flag=0;
				break;
			}
			else flag=1;
		}
		if(flag==1){
			bool mar=false;
			while(pro2){
				two[++mm]=pro2%2;
				pro2/=2;
			}
			for(int i=1;i<=mm/2;i++)
			{
				if(two[i]!=two[mm-i+1]){mar=true;break;}
			}
			if(!mar) ans++;
		}
	}
	cout<<ans;
	return 0;
}