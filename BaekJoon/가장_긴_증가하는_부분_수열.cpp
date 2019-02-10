#include <iostream>
using namespace std;
int p[1001];
int dp[1001];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];
	dp[0] = p[0] = 0;
	for (int i = 1; i <= N; i++) {
		int maxnum = -1;
		for (int j = 0; j < i; j++) {
			if (p[j]<p[i] && dp[i]<dp[j]+1) {
				maxnum = p[j];
				dp[i] = dp[j] + 1;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= N; i++) if (res < dp[i]) res = dp[i];
	cout << res;
}