#include <iostream>
#include <cstring>
using namespace std;
int C, N;
const int MOD = 1000000007;
int dp[102]; //모든 가능한 타일의 경우
int asym[102]; //가능한 비대칭 타일 개수

void tile(int n)
{
	int& res = dp[n];
	if (n == 1 || n == 0) {
		res = 1;
		return;
	}
	if (res != -1) return;
	tile(n - 1);
	tile(n - 2);
	res = (dp[n - 1] + dp[n - 2]) % MOD;
	return;
}
int tile2(int n)
{
	int& res = asym[n];
	if (res != -1) return res;
	if (n == 1 || n == 2) return 0;
	if (n % 2 == 1) {
		return res = (dp[n] - dp[n/2] + MOD) % MOD;
	}
	res = (dp[n] - dp[n / 2] + MOD) % MOD;
	res = (res - dp[(n - 1) / 2] + MOD) % MOD;
	return res;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		memset(asym, -1, sizeof(asym));
		tile(N);
		cout << tile2(N) << endl;
	}
}