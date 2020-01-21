#include <iostream>
using namespace std;
int p[33][33];
long long dp[33][33][3]; // 0 : 가로, 1 : 대각선, 2 : 세로
int N;

int main()
{
	cin >> N;
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> p[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (i == 1 && j == 2) continue;
			if (p[i][j] == 1) continue;

			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
			dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][1];
			if (p[i - 1][j] == 0 && p[i][j - 1] == 0)
				dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1];
		}
	}
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}