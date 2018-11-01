#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int Maxn=100005;
int a[Maxn]={0},b[Maxn]={0},c[Maxn]={0},M;
void Read()
{  int i,j,Len;char ch[50];
scanf("%s",&ch);
Len=strlen(ch);
for(i=0;i<Len;i++){j=(Len-i+3)/4;a[j]=a[j]*10+ch[i]-'0';}
a[0]=(Len+3)/4;
scanf("%d",&M);
}
void Print()
{  int i;
printf("%d",b[b[0]]);
for(i=b[0]-1;i>0;i--)
{  printf("%d",b[i]/1000);
printf("%d",b[i]/100%10);
printf("%d",b[i]/10%10);
printf("%d",b[i]%10);
}
printf("\n");
}
void Multiply()
{  int i,j;
memset(c,0,(c[0]+1)*sizeof(int));
for(i=1;i<=a[0];i++)
	 for(j=1;j<=b[0];j++)c[i+j-1]+=a[i]*b[j];
c[0]=a[0]+b[0]-1;
for(i=1;i<=c[0];i++){c[i+1]+=c[i]/10000;c[i]%=10000;}
if(c[c[0]+1]>0)c[0]++;
memcpy(b,c,(c[0]+1)*sizeof(int));
}
void Divide(int x)
{  int i,j=0;
for(i=b[0];i>0;i--){j=j*10000+b[i];c[i]=j/x;j=j%x;}
c[0]=b[0];
while(c[0]>1&&c[c[0]]==0)c[0]--;
memcpy(b,c,(c[0]+1)*sizeof(int));
}
void Subtract()
{  int i=1;
while(a[i]==0)a[i++]=9999;
a[i]--; if(a[a[0]]==0)a[0]--;
}
int main()
{  int i;
Read();
b[0]=b[1]=1;
for(i=1;i<=M;i++)
{	Multiply();
	Divide(i);
	Subtract();
}
Print();
}
