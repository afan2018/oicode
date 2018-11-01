#include <iostream>
using namespace std;
int main(){
    int L,R,s=0,i,x=0;
    cin>>L>>R;
    for(i=L;i<=R;i++)
    {x=i;
        while(x>0)
        
        {if(x%10==2)
                s++;
            x=x/10;}
    }
    cout<<s;
    return 0;
}