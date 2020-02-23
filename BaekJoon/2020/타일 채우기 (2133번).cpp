#include <iostream>
using namespace std;
int N;
int dp[301];

int main()
{
	cin >> N;
	dp[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = 4; j <= i - 2; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
		dp[i] += 2;
	}
	cout << dp[N];
}