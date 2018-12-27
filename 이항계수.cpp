/*
#include <iostream> 
using namespace std;
long long dp[1002][1002];
int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		dp[i][0] = 1;
		dp[i][1] = i;
		for(int j=2;j<=K;j++){
			dp[i][j] = (dp[i-1][j]+ dp[i-1][j-1])%10007;
		}
	}
	cout<<dp[N][K];
}
*/
