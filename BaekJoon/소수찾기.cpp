#include <iostream>
using namespace std;
bool p[1000001];

int main()
{
	int M,N;
	cin>>M>>N;
	
	p[1] = 0;
	for(int i=2;i<=N;i++) p[i] = true;
		
	for(int i=2;i*i<=N;i++){
		if(!p[i]) continue;
		for(int j=i+i;j<=N;j+=i){
			p[j]=false;	
		}
	}
	
	
	for(int i=M;i<=N;i++){
		if(p[i]) printf("%d\n",i);
	}
}
