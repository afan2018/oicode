#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,seq[20]={0},ans=0,tmp=0,cnt=0,fail=0;
int main()
{
	scanf("%lld",&n);
	while(1)
	{
		if(cnt>15) {fail=1;break;}
		tmp=n;
		ans++;
		cnt=0;
		while(tmp)
		{
			seq[++cnt]=tmp%10;
			tmp/=10;
		}
		ll fl=1;
		for(ll i=1;i<=cnt;i++)
			if(seq[i]!=seq[cnt-i+1])
				fl=0;
		if(fl) {ans--;break;}
		ll sum=0,idx=1;
		for(ll i=cnt;i>=1;i--)
		{
			sum+=seq[i]*idx;
			idx*=10;
		}
		sum+=n;
		tmp=sum;
		cnt=0;
		while(tmp)
		{
			seq[++cnt]=tmp%10;
			tmp/=10;
		}
		fl=1;
		for(ll i=1;i<=cnt;i++)
			if(seq[i]!=seq[cnt-i+1])
				fl=0;
		if(fl) break;
		n=sum;
	}
	if(fail) printf("Fail!");
	else printf("%lld",ans);
	return 0;
}
