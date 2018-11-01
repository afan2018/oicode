#include<iostream>
using namespace std;
int main(){
	string num;
	int len=0,n=0,maxx=0,sit=0;
	cin>>num>>n;
	len=num.length();
	while(n)
	{
		for(int j=0;j<len-1;j++)
			if(num[j]>num[j+1])
			{
				for(int k=j;k<len-1;k++)
					num[k]=num[k+1];
				break;
			}
		n--,len--;
	}
	int head=0,fg=0;
	while(num[head]=='0')head++;
	for(int i=head;i<len;i++)
		cout<<num[i];
	return 0;
}