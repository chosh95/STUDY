#include <iostream>
using namespace std;
int p[1001];
void sequence(int N);
int main()
{
	int N,count=0;;
	cin>>N;
	for(int i=1;i<=N;i++){
		sequence(i);
		if(p[i]==1) count++;
	}
	cout<<count;	
}
void sequence(int N)
{
	if(N<100) p[N]=1;
	else if(N<1000){
		int a = N/100;
		int b = N%100;
		int c = b%10;
		b = b/10;
		if(a-b == b-c) p[N]=1;
	}
	else if(N==1000) p[N]=0;
}
