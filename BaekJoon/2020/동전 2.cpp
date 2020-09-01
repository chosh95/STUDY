#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int p[101];
int dp[10001];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 0; i <= k; i++)
		dp[i] = 987654321;

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = p[i]; j <= k; j++) {
			if (p[i] == j) dp[j] = 1;
			dp[j] = min(dp[j], dp[j - p[i]] + 1);
		}
	}

	if (dp[k] == 987654321)
		cout << -1;
	else
		cout << dp[k];
}