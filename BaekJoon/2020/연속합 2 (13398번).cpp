#include <iostream>
#include <algorithm>
using namespace std;
int p[100002];
int dp[100002][2];
int N;

int main()
{
	cin >> N;
	for (int i = 2; i <= N+1; i++) cin >> p[i];

	int res = -987654321;
	for (int i = 2; i <= N+1; i++) {
		dp[i][0] = max(dp[i - 1][0] + p[i], p[i]);

		dp[i][1] = max(dp[i - 2][0] + p[i], p[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][1] + p[i]);

		res = max(res, max(dp[i][0], dp[i][1]));
	}


	cout << res;
}