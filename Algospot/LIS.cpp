#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int C, N;
int p[502];
int dp[502];

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));	
		for (int i = 1; i <= N; i++) cin >> p[i];
		int res = 1;
		for (int i = 1; i <= N; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (p[j] < p[i]) {
					if (dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
				}
			}
			res = max(res, dp[i]);
		}
		cout << res <<"\n";
	}
}