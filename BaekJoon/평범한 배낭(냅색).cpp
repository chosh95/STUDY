#include <iostream>
#include <algorithm>
using namespace std;
int p[101][2];
int dp[101][100001]; //i번째 까지 k의 무게일 때 가치
int N, K;
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> p[i][0] >> p[i][1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - p[i][0] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i][0]] + p[i][1]);
			}
		}
	}
	cout << dp[N][K];
}