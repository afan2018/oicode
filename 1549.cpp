#include<iostream>
using namespace std;
int mat1[20][20]={0},mat2[20][20]={0},ans=0,n,m,k;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mat1[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=k;j++)
            cin>>mat2[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            int ans=0;
            for(int p=1;p<=m;p++)
                ans+=mat1[i][p]*mat2[p][j];
            cout<<ans<<' ';
        }
        cout<<endl;
    }
    return 0;
}
