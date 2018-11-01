#include<iostream>
using namespace std;
char pht[80][80]={' '};
int scned[80][80]={0},line,raw,cow=0,room=0,maX=0,maY=0,miX=line,miY=raw,area=0;
void Judge(int x,int y)
{
	if(x<1||x>line||y<1||y>raw||pht[x][y]!='#')return;
	if(scned[x][y])return;
	maX=max(x,maX);
	maY=max(y,maY);
	miX=min(x,miX);
	miY=min(y,miY);
	scned[x][y]=1;
	area++;
	Judge(x+1,y);
	Judge(x-1,y);
	Judge(x,y+1);
	Judge(x,y-1); 
	return;
}
void Satellite_Photo()
{
	for(int i=1;i<=line;i++)
		for(int j=1;j<=raw;j++)
			if(!scned[i][j]&&pht[i][j]=='#')
			{
				area=0;maX=miX=i;maY=miY=j;
				Judge(i,j);
				if((maX-miX+1)*(maY-miY+1)==area)room++;
					else cow++;
			}
} 
int main(){
	cin>>line>>raw;
	for(int i=1;i<=line;i++)
		for(int j=1;j<=raw;j++)
			cin>>pht[i][j];
	Satellite_Photo();
	cout<<room<<endl<<cow;
	return 0;
}