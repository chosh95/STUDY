#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1001];
int dp[1001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	int res = p[1];
	for (int i = 1; i <= N; i++) {
		dp[i] = p[i];
		for (int j = 1; j <= i; j++) {
			if (p[i] > p[j] && dp[i] < dp[j] + p[i])
				dp[i] = dp[j] + p[i];
		}
		res = max(res, dp[i]);
	}
	cout << res;
}