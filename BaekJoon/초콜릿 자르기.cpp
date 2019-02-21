#include <iostream>
using namespace std;
int dp[301][301];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dp[i][1] = i - 1;
	for (int j = 1; j <= M; j++) dp[1][j] = j - 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i >= j) dp[i][j] = dp[i][1] * j + j - 1;
			else dp[i][j] = dp[1][j] * i + i - 1;
		}
	}
	cout << dp[N][M];
}