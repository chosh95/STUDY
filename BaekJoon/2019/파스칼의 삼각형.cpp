#include <iostream>
using namespace std;
int dp[31][31];
int main()
{
	int N,K;
	cin>>N>>K;
	dp[1][1] = 1;
	dp[1][0] = 0;
	for(int i=2;i<=N;i++){
		for(int j=1;j<=K;j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	cout<<dp[N][K];
}
