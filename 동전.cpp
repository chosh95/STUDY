/*
#include <iostream> 
using namespace std;
int p[11]; 
int main()
{
	int N,K,res=0;
	cin>>N>>K;
	for(int i=1;i<=N;i++)
		cin>>p[i];
			
	int j = N;
	bool t = true;
	while(t){
		if(K/p[j] != 0){
			res+=K/p[j];
			K %= p[j];
		}
		if(K<=0) t = false;
		j--;
	}
	cout<<res;
}
*/
