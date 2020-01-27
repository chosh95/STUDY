#include <iostream>
#include <cstring>
using namespace std;
int T;
int N, M;
int dp[31][31];

void bridge()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= M; i++) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == j) dp[i][j] = 1;
			else {
				for (int k = i-1; k <= j - 1; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
}
int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> M;
		bridge();
		cout << dp[N][M] << endl;
	}
}