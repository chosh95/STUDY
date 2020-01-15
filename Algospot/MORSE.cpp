#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N, M, K;
int dp[201][201];
int skip;
const int OVER = 1000000000 + 100; //overflow를 막기위한 값 k가 항상 10억 이하이므로 그 이상의 값은 필요없다.
void bino(int n, int m)
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = min(OVER, dp[i - 1][j-1] + dp[i - 1][j]);
		}
	}
}
void morse(int n, int m, string s) 
{
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (dp[n + m][m] <= skip) {
		skip -= dp[n + m][n];
		return;
	}
	if (n > 0)		morse(n - 1, m, s + "-");
	if (m > 0) 		morse(n, m - 1, s + "o");
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> M >> K;
		bino(N, M);
		skip = K-1; //k-1개를 건너뛰기
		morse(N, M, "");
	}
}