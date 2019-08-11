#include <iostream>
#include <algorithm>
using namespace std;
int T, W;
int p[1001];
int dp[3][1001][32]; // 위치, 시간, 이동 횟수

int main()
{
	cin >> T >> W;
	for (int i = 1; i <= T; i++) cin >> p[i];
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= W + 1; j++) { //안 움직이는 경우 포함
			if (p[i] == 1) {
				dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1);
				dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
			}
			else {
				if (i == 1 && j == 1) continue;
				dp[1][i][j] = max(dp[2][i - 1][j - 1], dp[1][i - 1][j]);
				dp[2][i][j] = max(dp[1][i - 1][j - 1] + 1, dp[2][i - 1][j] + 1);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= W + 1; i++) res = max(res, max(dp[1][T][i], dp[2][T][i]));
	cout << res;
}

