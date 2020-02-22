#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1000010];

int main()
{
	cin >> N;
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= N; i++) 
		dp[i] = 99999999;
	
	for (int i = 1; i <= N; i++) {
		for (int nx : {i + 1, i * 2, i * 3}) {
			if (nx > N) continue;
			dp[nx] = min(dp[nx], dp[i] + 1);
		}
	}
	cout << dp[N];
}