#include<iostream>
using namespace std;
int wline(int a){
    int i,lim=0;
    for(i=1;true;i++){
        lim+=i;
        if(lim>=a)break;
    }
    return i;
}
int main(){
    int line,n,x=0,y=0,last=0,dis=0;
    cin>>n;
    line=wline(n);
    last=(line*(line-1))/2;
    dis=n-last;
    if(line%2==0)
    {
        y=line;
        x=1;
        y-=dis-1;
        x+=dis-1;
    }
    if(line%2==1)
    {
        y=1;
        x=line;
        y+=dis-1;
        x-=dis-1;
    }
    cout<<x<<'/'<<y<<' ';
    return 0;
}
