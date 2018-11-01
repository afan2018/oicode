#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a[20][20],n,dir=0,flag=0,sta=0;
    cin>>n;
    memset(a,0,sizeof(a));
    if(n%2==0)flag=1;//even 1 odd 0
    a[1][1]=1;
    int x=1,y=1,i=1,max=n*n;
    while(i<=max-1)
    {
        if(dir==0)//down x行y列
        {
            x++,i++;
            a[x][y]=i;
            if(sta==0)dir=1;
            if(sta==1)dir=3;
            continue;
        }
        if(dir==1)//right up
        {
            y++,x--,i++;
            a[x][y]=i;
            if(x==1&&y==n&&flag==1&&sta==0)
            {
                dir=0,sta=1;
                continue;
            }
            if(x==1&&sta==0)dir=2;
            if(y==n&&sta==1)dir=0;
            
            continue;
        }
        if(dir==2)//right
        {
            y++,i++;
            a[x][y]=i;
            if(sta==0)dir=3;
            if(sta==1)dir=1;
            continue;
        }
        if(dir==3)//left down
        {
            y--,x++,i++;
            a[x][y]=i;
            if(x==n&&y==1&&flag==0&&sta==0){
                dir=2,sta=1;
                continue;
            }
            if(x==n&&sta==1)dir=2;
            if(y==1&&sta==0)dir=0;
            continue;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
        cout<<endl;
    }
        return 0;
}
