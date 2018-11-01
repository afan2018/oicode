#include<iostream>
using namespace std;
bool man[105]={0};
int main(){
	int n,i=0,m,j=0;
	cin>>n>>m;
	int c=n;
	while(c){
		if(!man[j]){
			i++;
			if(i==m){
				cout<<j+1<<' ';
				man[j]=1;
				c--;
				i=0;
			}
		}
		j=(j+1)%n;
	}
	return 0;
}
