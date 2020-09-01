#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int dp[100001];
int p[101];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> p[i];
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (p[i] > k) continue;
		for (int j = 1; j <= k; j++) {
			if (j - p[i] >= 0)
				dp[j] += dp[j - p[i]];
		}
	}
	cout << dp[k];
}