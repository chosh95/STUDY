#include <iostream>
using namespace std;
int p[101][101];
long long dp[101][101];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i + p[i][j] <= N && p[i][j]) dp[i+p[i][j]][j] += dp[i][j];
			if (j + p[i][j] <= N && p[i][j]) dp[i][j + p[i][j]] += dp[i][j];
		}
	}
	cout << dp[N][N];
}