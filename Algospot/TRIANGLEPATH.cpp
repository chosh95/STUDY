#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int C, N;
int p[102][102];
int dp[102][102];

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= i; j++) 
				cin >> p[i][j];
		memset(dp, 0, sizeof(dp));
		dp[1][1] = p[1][1];
		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i + 1][j] = max(dp[i+1][j],(p[i+1][j] + dp[i][j]));
				dp[i + 1][j + 1] = max(dp[i+1][j+1],(p[i+1][j+1]+dp[i][j]));
			}
		}
		int res = 0;
		for (int i = 1; i <= N; i++) res = max(res, dp[N][i]);
		cout << res << "\n";
	}
}