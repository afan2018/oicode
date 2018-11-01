#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int heap[1000005]={0},n;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	scanf("%d",&n);
	int num,sm1,sm2,sum=0;
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",&num);
		q.push(num);
	}
	while(q.size()>1)
	{
		sm1=q.top();
		q.pop();
		sm2=q.top();
		q.pop();
		sum+=sm1+sm2;
		q.push(sm1+sm2);
	}
	cout<<sum;
	return 0;
}