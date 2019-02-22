#include <iostream>
using namespace std;
int p[1001];
int dp[1001];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if (dp[j] + 1 > dp[i] && p[j] < p[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (res < dp[i]) res = dp[i];
	}
	cout << res;
}