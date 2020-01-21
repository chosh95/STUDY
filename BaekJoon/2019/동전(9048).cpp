#include <iostream>
#include <memory.h>
using namespace std;
int p[21];
int dp[10001];

int main()
{
	int T;
	cin >> T;
	while (T--) {
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));
		int N, M;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> p[i];
		cin >> M;
		dp[0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = p[i]; j <= M; j++) {
				dp[j] += dp[j - p[i]];
			}
		}
		cout << dp[M] << "\n";
	}
}