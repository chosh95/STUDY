#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1500002];
long long p[1500002][2];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i][0] >> p[i][1];
	int res = 0;
	for (int i = 1; i <= N + 1; i++) {
		if (res < dp[i]) res = dp[i];
		if (i + p[i][0] > N+1) continue;
		dp[i + p[i][0]] = max(res + p[i][1], dp[i+p[i][0]]);
	}
	cout << res;
}