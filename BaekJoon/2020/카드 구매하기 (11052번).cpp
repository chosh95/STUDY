#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[10001];
int dp[10001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	dp[1] = p[1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[N];
}