#include<iostream>
using namespace std;
int dirx[12]={2,1,1,-1,-1,2,-2,-2,2,2,-2,-2},diry[12]={1,2,-2,2,-2,-1,1,-1,2,-2,2,-2},pad[1005][1005]={0};
struct node{int x,y,tms;}quene[100005],sit[5];
void Horse()
{
	int head=1,tail=1,newx=0,newy=0,flag=1;
	quene[1].x=1;quene[1].y=1;quene[1].tms=0;
	pad[1][1]=0;
	while(head<=tail)
	{
		for(int i=0;i<12;i++)
		{
			newx=quene[head].x+dirx[i]; 
			newy=quene[head].y+diry[i];
			if(newx>0&&newx<=100&&newy>0&&newy<=100&&!pad[newx][newy])
			{
				tail++;
				quene[tail].x=newx;
				quene[tail].y=newy;
				pad[newx][newy]=quene[tail].tms=quene[head].tms+1;
			}
			if(pad[sit[1].x][sit[1].y]>0&&pad[sit[2].x][sit[2].y]>0)
			{
				cout<<pad[sit[1].x][sit[1].y]<<endl<<pad[sit[2].x][sit[2].y];
				return;
			}
		}
		head++;
	}
}
int main(){
	cin>>sit[1].x>>sit[1].y>>sit[2].x>>sit[2].y;
	Horse();
	return 0;
}