#include<iostream>
#include<cstring>
using namespace std;
string mat[12005],mod;
int n,k,mal,modl,flag=0,maxl;
int lens,lent,P[25500],maxx=0;//前面最大匹配的定位
void Get_next(string t)//注意字符串都是从1开始匹配 
{  int i,j;
   P[1]=0;j=0;
   for(i=2;i<=lent;i++)
   {  while(j>0&&t[j+1]!=t[i])j=P[j];//向前寻找
      if(t[j+1]==t[i])j++;
      P[i]=j;  
   }
}
int KMP(string s,string t)//返回第一次匹配的位置
{  int i,j;
   j=0;  //指针初始化
   for(i=1;i<=lens;i++)
   {  while(j>0&&t[j+1]!=s[i])j=P[j];
      if(t[j+1]==s[i])j++;
      maxx=max(maxx,j);
      if(j==lent)return i-lent+1;
   }
   return 0;
}
int main()
{  
	//freopen("game1.in","r",stdin);
//	freopen("game.out","w",stdout);
std::ios::sync_with_stdio(false);
	cin>>n>>mod;
	mod=' '+mod;
	for(int i=1;i<=n;i++) 
	 {cin>>mat[i];mat[i]=' '+mat[i];}
	
	for(int i=1;i<=n;i++)
	{
		lens=mat[i].length()-1;
   		lent=mod.length()-1;
  		Get_next(mod);
   		if(KMP(mat[i],mod)) {cout<<"My God.";return 0;}
	}
	cout<<"My CS.\n"<<maxx;
	return 0;
}