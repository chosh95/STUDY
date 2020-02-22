#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[3][100001];
int dp[3][100001];
int T, N;

int main()
{
	cin >> T;
	while (T--) {
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= N; j++)
				cin >> p[i][j];

		dp[1][1] = p[1][1];
		dp[2][1] = p[2][1];

		for (int i = 2; i <= N; i++) {
			dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + p[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + p[2][i];
		}

		cout << max(dp[2][N], dp[1][N]) << "\n";
	}
}