#include <iostream>
#include <algorithm>
using namespace std;
int n[100002];

int main()
{
	int N;
	cin>>N; 
	for(int i=0;i<N;i++) cin>>n[i];
	if(N==1) cout<<n[0];
	else{
		sort(n,n+N);
		for(int i=0;i<N;i++) n[i] *= (N-i);
		sort(n,n+N);
		cout<<n[N-1];
	}
}
