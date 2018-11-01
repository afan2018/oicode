#include<iostream>
#include<algorithm>
using namespace std;
const int table[15][6]={{0,0},{0,0},{4,2,4,8,6},{4,3,9,7,1},{0,0,0},{0,0},{0,0},{4,7,9,3,1},{4,8,4,2,6},{0,0,0}};
int a,b;
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        a%=10;
        if(a==0) {puts("0");continue;}
        if(b==0) {puts("1");continue;}
        if(a==5||a==6||a==1) {printf("%d\n",a);continue;}
        if(a==4)
        {
            if(b%2) puts("4");
            else puts("6");
            continue;
        }
        if(a==9)
        {
            if(b%2) puts("9");
            else puts("1");
            continue;
        }
        int mod=table[a][0];
        if(b%mod==0) b=mod;
        else b%=mod;
        printf("%d\n",table[a][b]);
    }
    return 0;
}
