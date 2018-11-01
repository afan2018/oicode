#include<iostream>
const long long MOD=12345678910ll;
long long S[100005]={0},top=0,n;
int main()
{
	std::cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		std::cin>>x;
		if(!x) {S[++top]=x;continue;}
		if(S[top]) S[top-1]=(S[top-1]+(S[top]*2)%MOD)%MOD;
		else S[top-1]++;
		top--;
	}
	std::cout<<S[0];
	return 0;
}