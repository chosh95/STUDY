#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, M, K;
int dp[201][201];
int skip;

void bino()
{
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = min(1000000000, dp[i - 1][j] + dp[i-1][j - 1]);
		}
	}
}

void solve(int n, int m, string str)
{
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << str;
		--skip;
		return;
	}
	if (dp[n+m][m] <= skip) {
		skip -= dp[n+m][m];
		return; 
	}
	if (n > 0)
		solve(n - 1, m, str + "a");
	if (m > 0)
		solve(n, m - 1, str + "z");
}
int main()
{
	cin >> N >> M >> K;

	bino();
	skip = K - 1;

	if (dp[N + M][M] <= skip) {
		cout << -1;
		return 0;
	}

	solve(N, M, "");
}