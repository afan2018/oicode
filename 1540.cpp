#include<iostream>
#include<cstring>
using namespace std;
char sco[100005];
int vabs(int a,int b){
    int abs=0;
    if(a>=b)abs=a-b;
    else abs=b-a;
    return abs;
}
int main(){
    int len=0,w=0,l=0,abs=0;
    for(int i=1;true;i++)
    {
        cin>>sco[i];
        len++;
        if(sco[i]=='E')break;
    }
    for(int i=1;i<=len;i++)
    {
        abs=vabs(w,l);
        if(((w>=11)||(l>=11))&&abs>=2)
        {
            cout<<w<<':'<<l<<endl;;
            w=0,l=0;
        }
        if(sco[i]=='W')w++;
        if(sco[i]=='L')l++;
        if(i==len)cout<<w<<':'<<l<<endl;
    }
    return 0;
}
/*
WWWWWWWWWWWWWWWWWWWW
WWLWE
*/
