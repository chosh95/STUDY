#include <iostream>
#include <memory.h>
using namespace std;
int p[1001];
int dp[1001];
int N;

int main()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) cin >> p[i];
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 1; i < N; i++) {
		if (i != 1 && dp[i] == 0) break;
		for (int j = i + 1; j <= i + p[i]; j++) {
			if (j > N) break;
			if (dp[j] == -1 || dp[j] > dp[i] + 1) dp[j] = dp[i] + 1;
		}
	}
	cout << dp[N];
}