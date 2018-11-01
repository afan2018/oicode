#include<iostream>
#include<iomanip>
using namespace std;
string str;
int n,cnt=0,sum=0,ccnt=0;
char ch;
int main()
{
    cin>>n>>ch;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        if(str[0]=='c'&&str[1]=='o'&&str[2]=='n')
            cnt++;
        for(int i=0;i<str.length();i++)
            if(str[i]==ch)
                ccnt++;
        sum+=str.length();
    }
    cout<<cnt<<'\n'<<fixed<<setprecision(2)<<double(ccnt)/double(sum)*100<<'%';
    return 0;
}
