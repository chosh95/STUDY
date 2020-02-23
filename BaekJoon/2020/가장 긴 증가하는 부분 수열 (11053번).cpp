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
	int res = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i] > p[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				res = max(res, dp[i]);
			}
		}
	}

	cout << res;
}