#include<iostream>
using namespace std;
int main()
{
    char a,b[121000];
    int huahua=0,duishou=0,i,len=0;
    while(1)
    {
        len++;
        cin>>b[len];
        if(b[len]=='E') break;
    }
    for(i=1;i<len;i++)
    {
        if(b[i]=='W')
        {
            huahua++;
            if((duishou>=11||huahua>=11)&&abs(huahua-duishou)>=2)
            {
                cout<<huahua<<":"<<duishou<<endl;
                huahua=0;duishou=0;
            }
        }
        else
 	    {
            duishou++;
            if((duishou>=11||huahua>=11)&&abs(duishou-huahua)>=2)
            {
                cout<<huahua<<":"<<duishou<<endl;
                huahua=0;duishou=0;
		    }
        }
    }
    cout<<huahua<<":"<<duishou<<endl<<endl;
    huahua=0;duishou=0;
    for(i=1;i<len;i++)
    {
        if(b[i]=='W')
        {
            huahua++;
            if(huahua>=21&&abs(huahua-duishou)>=2)
            {
                cout<<huahua<<":"<<duishou<<endl;
                huahua=0;duishou=0;
            }
        }
        else
 	    {
            duishou++;
            if(duishou>=21&&abs(duishou-huahua)>=2)
            {
                cout<<huahua<<":"<<duishou<<endl;
                huahua=0;duishou=0;
 		    }
        }
    }
    cout<<huahua<<":"<<duishou<<endl;
    cout<<endl;
	return 0;
}
