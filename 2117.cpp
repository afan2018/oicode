#include<iostream>
#include<cstring>
using namespace std;
int seq[3][5]={0},flag=0,temp[5]={0},sta[3][5]={0},ff=0,back[3][5]={0},cnt=0;
long long tar=0,ssta=0;
bool h[50000000]={0};
struct node{char opr;int tim,fr,seqq[3][5];}quene[10007];
long long Calc(int a[3][5])
{
    long long num=0;
    int o=1;
    for(int i=1;i<=4;i++)num+=a[2][i]*o,o*=9;
    for(int i=4;i>=1;i--)num+=a[1][i]*o,o*=9;
    return num;
}
void Init()
{
    for(int i=1;i<=4;i++)sta[1][i]=i;
    for(int i=1;i<=4;i++)sta[2][i]=9-i;
    for(int i=1;i<=4;i++)cin>>seq[1][i];
    for(int i=4;i>=1;i--)cin>>seq[2][i];
    ssta=Calc(sta);
    tar=Calc(seq);
}
void Operate(int flag,int now[3][5])
{
    if(flag==0)//A
    {
        memcpy(sta,now,sizeof(sta));
        for(int i=1;i<=4;i++)temp[i]=now[1][i];
        for(int i=4;i>=1;i--)sta[1][i]=now[2][i];
        for(int i=1;i<=4;i++)sta[2][i]=temp[i];
        return;
    }
    if(flag==1)//B
    {
        memcpy(sta,now,sizeof(sta));
        temp[1]=now[1][4],temp[2]=now[2][4];
        for(int i=1;i<=2;i++)
            for(int j=3;j>=1;j--)sta[i][j+1]=now[i][j];
        sta[1][1]=temp[1],sta[2][1]=temp[2];
        return;
    }
    if(flag==2)//C
    {
        memcpy(sta,now,sizeof(sta));
        temp[1]=now[1][2],temp[2]=now[1][3],temp[3]=now[2][2],temp[4]=now[2][3];
        sta[1][2]=temp[3],sta[1][3]=temp[1],sta[2][2]=temp[4],sta[2][3]=temp[2];
        return;
    }
}
void print(int pos)
{
    if(pos==1)return;
    cnt++;
    print(quene[pos].fr);
   // if(!cnt%60)cout<<endl;
    cout<<quene[pos].opr;
}
void BFS()
{
    int head=1,tail=1;
    long long neww=0;
    quene[1].opr=' ';quene[1].tim=0;h[ssta]=1;quene[1].fr=0;
    memcpy(quene[1].seqq,sta,sizeof(quene[1].seqq));
    while(head<=tail)
    {
        for(int i=0;i<=2;i++)
        {
            Operate(i,quene[head].seqq);
            neww=Calc(sta);
            if(!h[neww])
            {
                char ch=' ';
                if(i==0)ch='A';
                if(i==1)ch='B';
                if(i==2)ch='C';
                tail++;
               	quene[tail].tim=quene[head].tim+1;
                quene[tail].opr=ch;quene[tail].fr=head;
                memcpy(quene[tail].seqq,sta,sizeof(sta));
                h[neww]=1;
                if(neww==tar)
                {
                    cout<<quene[tail].tim<<endl;
                    print(tail);
                    return;
                }
            }
        }
        head++;
    }
}
int main(){
    Init();
    BFS();
    if(!cnt)cout<<cnt;
    return 0;
}