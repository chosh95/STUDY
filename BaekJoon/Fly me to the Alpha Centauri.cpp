/*
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		long long x,y;
		cin>>x>>y;
		long long dist = y-x, n=1, low, high;
		while(1){
			low = n*(n-1) + 1;
			high = n*(n+1);
			if(low<=dist && dist<=high) break;
			n++;
		}
		if(dist<=n*n) cout<<n*2-1<<endl;
		else cout<<n*2<<endl;;
	}
}*/
