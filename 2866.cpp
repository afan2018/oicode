#include<iostream>
#include<cstdio>
using namespace std;
int heap[1000005]={0},n;
void HeapUp()
{
	int temp,i;
	i=heap[0];
	while(i>1&&heap[i]>heap[i/2]){temp=heap[i],heap[i]=heap[i/2],heap[i/2]=temp,i/=2;}
}
void HeapDown()
{
	int temp,i,j;
	i=1;
	while(i*2<=heap[0])
	{
		if(i*2==heap[0]||heap[i*2]>heap[i*2+1])j=i*2;
			else j=i*2+1;
		if(heap[i]<heap[j]){temp=heap[i],heap[i]=heap[j],heap[j]=temp,i=j;}
			else break;
	}
}
void SetHeap(int nm)
{
	heap[0]++;heap[heap[0]]=nm;
	HeapUp();
}
void Delete()
{
	//cout<<heap[1]<<endl;
	heap[1]=heap[heap[0]];
	heap[0]--;
	HeapDown();
}
int main(){
	scanf("%d",&n);
	int num,numm;
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",&num);
		if(num==1)
		{
			scanf("%d",&numm);
			SetHeap(numm);
		}
		if(num==2)Delete();
		if(num==3)printf("%d\n",heap[1]);
	}
	return 0;
}