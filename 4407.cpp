#include<iostream>
#include<algorithm>
using namespace std;
int seq[105]={0},n,k,ans=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        fill(seq+1,seq+k+1,0);
        for(int i=1;i<=k;i++)
            cin>>seq[i];
        sort(seq+1,seq+k+1);
        ans+=seq[k];
    }
    cout<<"total="<<ans;
    return 0;
}
