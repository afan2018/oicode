#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[105];
int cnt=1,len,seq[105],seq1[105];
bool C()
{
	for(int i=1;i<=len;i++)
		if(seq[i]!=seq1[i]) return false;
	return true;
}
int main()
{
	scanf("%s",ch);
	len=strlen(ch);
	for(int i=0;i<strlen(ch);i++)
		seq1[i+1]=seq[i+1]=ch[i]-'a'+1;
	sort(seq+1,seq+len+1);
	do
	{
		if(C()) {printf("%d",cnt);return 0;}
		cnt++;
	}
	while(next_permutation(seq+1,seq+1+len));
}