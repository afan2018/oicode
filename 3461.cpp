#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;
int ans=0x7fffffff,xx[100005],yy[100005],nn[100005],n,d,i,j;
bool cmp(int x,int y){return xx[x]<xx[y];}
multiset<int>q;//集合
int main(){
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d%d",&xx[i],&yy[i]),nn[i]=i;
	sort(nn+1,nn+n+1,cmp);//按x排序
    q.insert(yy[nn[1]]);i=j=1;
	while(1){
		if(*q.rbegin()-*q.begin()>=d){
			ans=min(ans,xx[nn[j]]-xx[nn[i]]);
			multiset<int>::iterator it=q.find(yy[nn[i++]]);
			q.erase(it); 
		}
		else{
			if(j==n) break;
			q.insert(yy[nn[++j]]);
		}
	}
	printf("%d",ans==0x7fffffff?-1:ans); 
	return 0;}
