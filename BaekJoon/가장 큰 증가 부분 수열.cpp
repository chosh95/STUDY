#include <iostream>
using namespace std;
int p[1004];
int dp[1004];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = p[i];
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (p[j] < p[i] && dp[i] < dp[j] + p[i])
				dp[i] = dp[j] + p[i];
			if (max < dp[i]) max = dp[i];
		}
	}
	cout << max;
}