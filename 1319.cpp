#include<iostream>
using namespace std;
int n,seq[10005]={0},cnt=0,sum=0,del=0,cntt=0,a[10005]={0};
void Mul(int k)   
{	
	int i; 
	if(k==0){for(i=0;i<=101;i++)a[i]=0;a[0]=0;return;} 
	for(i=1;i<=a[0];i++)a[i]=a[i]*k;
	for(i=1;i<=a[0];i++){a[i+1]+=a[i]/10;a[i]%=10;} 
	while(a[a[0]+1]>0){a[0]++;a[a[0]+1]=a[a[0]]/10;a[a[0]]=a[a[0]]%10;} 
}
void Print()  //打印输出
{ 
	int i;
	if(a[0]==0){cout<<0<<endl;return;}
	for(i=a[0];i>0;i--)cout<<a[i];cout<<endl;
}
int main(){
	cin>>n;
	cnt=1;
	while(1)
	{
		cnt++;
		sum+=cnt;
		if(sum>n) {sum-=cnt;break;}
		seq[cnt-1]=cnt;
		cntt++;
	}
	del=n-sum;
	int temp=cntt,sit=cntt;
	while(del>0)
	{
		if(sit==0) sit=temp;
		seq[sit]++;
		sit--;
		del--;
	}
	for(int i=1;i<=cntt;i++)
		cout<<seq[i]<<' ';
	cout<<endl;
	a[1]=1;
	a[0]=1;
	for(int i=1;i<=cntt;i++) 
		Mul(seq[i]);
	Print();
	return 0;
}
