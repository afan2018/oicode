#include<iostream>
using namespace std;
int n,m,nk,bj[5001],ans[5001],f[3001][3001]={0};
string a,b,s1;
bool ryl()
{  int i,j=1,k;
   for(i=1;i<=nk;i++)
   {	j=1;
      while(j<=nk&&bj[j])j++;
	  if(j>nk)return false;
      ans[j]=++ans[0];bj[j]--;
      //cout<<ans[ans[0]]<<' '<<ans[0]<<j<<endl;
      for(k=1;k<=nk;k++)
            if(f[j][k]!=0)bj[k]--;
   }
   return 1;
}
int main(){
	cin>>nk;
	cin>>n;
	cin>>b;
	for(int i=2;i<=n;i++){
		cin>>a;
		int j=0;
		while(j<a.length()&&j<b.length()&&a[j]==b[j])j++;
		if(j!=b.length())f[b[j]-'a'+1][a[j]-'a'+1]=1,bj[a[j]-'a'+1]++;
		b=a;
	}
	cin>>s1;
if(ryl())for(int i=0;i<s1.length();i++)cout<<char(ans[s1[i]-'a'+1]+'a'-1);
else cout<<0;
	return 0;
}