#include <iostream>
#include <algorithm>
using namespace std;
char p[1001][1001];
int dp[1001][1001];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> p[i][j];

	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (p[i][j] == '0') dp[i][j] = 0;
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
			}
			if (res < dp[i][j]) res = dp[i][j];
		}
	}
	cout << res * res;
}