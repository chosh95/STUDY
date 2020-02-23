#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1001];
int dp[1001];
int rdp[1001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (p[i] > p[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = N; i >= 1; i--) {
		rdp[i] = 1;
		for (int j = N; j > i; j--) {
			if (p[i] > p[j] && rdp[i] < rdp[j] + 1)
				rdp[i] = rdp[j] + 1;
		}
	}

	int res = 1;
	for (int i = 1; i <= N; i++) {
		res = max(res, dp[i] + rdp[i] - 1);
	}

	cout << res;
}
