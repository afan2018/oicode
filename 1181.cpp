#include<iostream>
using namespace std;
int cmp(char a,char b)
{
    if(a=='('&&b==')')return 0;
    if(a=='('||b=='(')return -1;
    if(b==')'||a=='*'||a=='/'||b=='+'||b=='-'||a==b)return 1;
    return -1;
}
int calc(int a,int b,char ch)
{
    switch(ch)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
int main(){
    int temp,num[255],numtop=-1,chtop=0,pos=0;
    char ch[255];
    string str;
    cin>>str;
    ch[0]='(',str+=")";
    while(pos<str.length())
    {
        if(str[pos]>='0'&&str[pos]<='9')
        {
            temp=0;
            while(str[pos]>='0'&&str[pos]<='9'&&pos<str.length())
                temp=temp*10+str[pos++]-'0';
            num[++numtop]=temp;
            continue;
        }
        switch(cmp(ch[chtop],str[pos]))
        {
            case 0:chtop--;pos++;break;
            case -1:ch[++chtop]=str[pos];pos++;break;
            case 1:num[numtop-1]=calc(num[numtop-1],num[numtop],ch[chtop]);
                numtop--;
                chtop--;
                break;
        }
    }
    cout<<num[0]<<endl;
    return 0;
}