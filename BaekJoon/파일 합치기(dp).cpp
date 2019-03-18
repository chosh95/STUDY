#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int p[501];
int dp[501][501];
int res;
int main()
{
	int T,K;
	cin >> T;
	while (T--) {
		cin >> K;
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= K; i++) {
			cin >> p[i];
			p[i] = p[i - 1] + p[i];
		}
		for (int j = 1; j < K; j++) {
			for (int i = 1; i <= K-j; i++) {
				dp[i][i + j] = 9999999999;
				for (int k = i; k < i+j; k++) {
					dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k + 1][i + j]);
				}
				dp[i][i + j] += p[i + j] - p[i - 1];
			}
		}
		cout << dp[1][K]<<"\n";
	}
}