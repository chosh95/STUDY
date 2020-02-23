#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[301];
int dp[301];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	dp[1] = p[1];
	dp[2] = p[1] + p[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + p[i - 1] + p[i], dp[i - 2] + p[i]);
	}
	
	cout << dp[N];
}