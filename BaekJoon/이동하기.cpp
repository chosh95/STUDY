#include <iostream>
using namespace std;
int p[1002][1002];
int dp[1002][1002];
int max(int a, int b, int c)
{
	int mn = 0;
	if (a >= mn) mn = a;
	if (b >= mn) mn = b;
	if (c >= mn) mn = c;
	return mn;
}
int main()
{
	int  N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + p[i][j];
		}
	}
	cout << dp[N][M];
}