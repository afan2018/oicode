#include<iostream>
#define max 255
using namespace std;
char ch[9]={' ','{','[','(','<','>',')',']','}'};
int main(){
	string str;
	int n,len;
	struct stack{int seq[max]={0};int top;}s;
	bool mark=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		mark=true;
		s.top=0;
		len=str.length();
		for(int j=0;j<len;j++)
		{
			int pos;
			for(pos=1;pos<=8;pos++)
				if(str[j]==ch[pos])break;
			if(pos<=4)
			{
				if(s.seq[s.top]>pos)
				{cout<<"NO"<<endl;mark=false;break;}
					else {s.seq[++s.top]=pos;}
			}
			else if(s.seq[s.top]+pos!=9) {cout<<"NO"<<endl;mark=false;break;}
				else s.top--;
		}
		if(mark)
			if(!s.top)cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
	}
	return 0;
}
/*
5
{[(<>)]}
[()]
<>()[]{}
[{}]
{()}
*/