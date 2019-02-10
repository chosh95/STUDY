#include <iostream>
#include <algorithm>
using namespace std;
int p[101];
int dp[10001];

int main()
{
	int N, K,tmp;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];
	sort(p+1 , p + N+1);
	for (int i = 1; i <= K; i++) {
		if (i%p[1] == 0) dp[i] = i / p[1];
		else dp[i] = 999999;
	}
	for (int j = 1; j <= N; j++) {
		for (int i = p[j]; i <= K; i++) {
			if (dp[i] > dp[i - p[j]] + 1) dp[i] = dp[i - p[j]] + 1;
		}
	}
	if (dp[K] == 999999) dp[K] = -1;
	cout << dp[K];
}