#include<iostream>
using namespace std;
int loop[15]={0},n,used[15]={0},sol=0;
int judge_prime(int sit,int now)
{
	if(!sit)return 1;
	int flag=1,sum=loop[sit]+now;
	for(int i=2; i*i<=sum; i++) if(sum%i==0)return 0;
	if(sit==n-1)
	{
		sum=loop[1]+now;
		for(int i=2; i*i<=sum; i++) if(sum%i==0) return 0;
	}
	return 1;
}
void print()
{
	for(int i=1; i<=n; i++)cout<<loop[i]<<' ';
	cout<<endl;
}
void prime_loop(int _try)
{
	if(_try>n)
	{
		sol++;
		print();
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(!used[i]&&judge_prime(_try-1,i))
		{
			loop[_try]=i;
			used[i]=1;
			prime_loop(_try+1);
			used[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	prime_loop(1);
	if(!sol)cout<<"NO";
	return 0;
}