#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[100001];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}

	cout << dp[N];
}