#include <iostream>
using namespace std;
const int MAX=100000;
int seq[100005]={0},n,b,tab[200005]={0},big,small,m=0,ans;
int main()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>seq[i];
		if(seq[i]==b) m=i;
	}
	tab[MAX]=1,big=small=0;
	for(int i=m+1;i<=n;i++)
	{
		if(seq[i]>b) big++;
		else small++;
		tab[big-small+MAX]++;
	}
	ans=tab[MAX],big=small=0;
	for(int i=m-1;i>=1;i--)
	{
		if(seq[i]>b) big++;
		else small++;
		ans+=tab[small-big+MAX];
	}
	cout<<ans;
	return 0;
}
