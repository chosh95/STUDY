#include <iostream>
using namespace std;
int N;
int p[101];
long long dp[101][21];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	dp[1][p[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + p[i] <= 20) dp[i][j + p[i]] += dp[i - 1][j];
				if (j - p[i] >= 0) dp[i][j - p[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 1][p[N]];
}