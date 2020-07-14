#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int t[1001], p[1001];
int dp[1001];

int dfs(int cur)
{
	if (cur > N) return 0;
	if (dp[cur] != -1) return dp[cur];
	dp[cur] = 0;
	for (int i = cur + t[cur]; i <= N + 1; i++) {
		dp[cur] = max(dp[cur], dfs(i)+p[cur]);
	}
	return dp[cur];
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> t[i] >> p[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0);
}