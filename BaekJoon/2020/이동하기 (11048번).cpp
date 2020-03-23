#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int p[1001][1001];
int dp[1001][1001];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> p[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			dp[i][j] += p[i][j];
		}
	}

	cout << dp[N][M];
}