#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int dp[41] = {1,0,3};
	for(int i=4;i<=N;i+=2){
		dp[i] = dp[i-2] * 3;
		for(int j=4;j<=i;j+=2){
			dp[i]+=2*dp[i-j];
		}
	}	
	cout<<dp[N];
	return 0;
}

