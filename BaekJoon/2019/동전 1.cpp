#include <iostream>
using namespace std;
int p[101];
int dp[10001];
int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++) cin>>p[i];
	dp[0] = 1;
	for(int i=1;i<=N;i++){
		for(int j=p[i];j<=K;j++){
			dp[j] += dp[(j-p[i])];
		}
	}
	cout<<dp[K];
}
