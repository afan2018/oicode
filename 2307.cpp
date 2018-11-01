#include<iostream>
using namespace std;
typedef long long ll;
string str;
char buffer[15];
ll len=0,cnt=1,ans=0;
int main()
{
    cin>>str;
    ll len=str.length();
    for(ll i=0;i<len-2;i++)
        if(str[i]!='-')
        {
            ans=(ans+(str[i]-'0')*cnt)%11;
            cnt++;
        }
    ans%=11;
    if((ans==str[len-1]-'0'&&ans!=10)||(ans==10&&str[len-1]=='X')) puts("Right");
    else
    {
        if(ans==10)
        {
            for(int i=0;i<len-1;i++)
                cout<<str[i];
            cout<<'X';
        }
        else
        {
            for(int i=0;i<len-1;i++)
                cout<<str[i];
            cout<<ans;
        }
    }
    return 0;
}
