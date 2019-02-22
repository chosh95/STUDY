#include <iostream>
using namespace std;
int p[1001];
int dp[1001][2];
int max(int a, int b)
{
	return a < b ? b : a;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i][0] = dp[i][1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if (dp[j][0] + 1 > dp[i][0] && p[j] < p[i]) {
				dp[i][0] = dp[j][0] + 1;
			}
			if (p[i] < p[j]) {
				dp[i][1] = max(dp[i][1],max(dp[j][0]+1, dp[j][1]+1));
			}
		}
	}
	int res=0;
	for (int i = 1; i <= N; i++) {
		res = max(res, dp[i][0]);
		res = max(res, dp[i][1]);
	}
	cout << res;
}