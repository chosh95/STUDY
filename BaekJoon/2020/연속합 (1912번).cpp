#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[100001];
int dp[100001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	int res = -987654321;
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i - 1] + p[i], p[i]);
		res = max(res, dp[i]);
	}
	
	cout << res;
}