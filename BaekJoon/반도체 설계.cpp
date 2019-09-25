#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[40002];
int dp[40002];
int res;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = 1;
	}
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (p[j] < p[i] && dp[j]>=dp[i]) dp[i] = dp[j] + 1;
		}
	}
	for (int i = 1; i <= N; i++) res = max(res, dp[i]);
	cout << res;
}