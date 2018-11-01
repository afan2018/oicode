#include<iostream>
using namespace std;
struct node{int sco1,sco2,fl1,fl2,num,ans;string str;}S[105];
int n,sum=0,maxx=0,pos;
char buffer[25];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char ch1,ch2;
        cin>>S[i].str>>S[i].sco1>>S[i].sco2>>ch1>>ch2>>S[i].num;
        S[i].fl1=(ch1=='Y');
        S[i].fl2=(ch2=='Y');
    }
    for(int i=1;i<=n;i++)
    {
        if(S[i].sco1>80&&S[i].num>=1) S[i].ans+=8000;
        if(S[i].sco1>85&&S[i].sco2>80) S[i].ans+=4000;
        if(S[i].sco1>90) S[i].ans+=2000;
        if(S[i].sco1>85&&S[i].fl2) S[i].ans+=1000;
        if(S[i].sco2>80&&S[i].fl1) S[i].ans+=850;
        sum+=S[i].ans;
        if(S[i].ans>maxx)
        {
            maxx=S[i].ans;
            pos=i;
        }
    }
    cout<<S[pos].str<<endl<<S[pos].ans<<endl<<sum<<endl;
    return 0;
}
