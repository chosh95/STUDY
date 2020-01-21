#include <iostream>
#include <algorithm>
using namespace std;
int p[3][1000002];
int dp[3][1000002];
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		for (int i = 1; i <= 2; i++) 
			for (int j = 1; j <= N; j++) cin >> p[i][j]; 
		
		dp[1][1] = p[1][1];
		dp[2][1] = p[2][1];

		for (int i = 2; i <= N; i++) {
			dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + p[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + p[2][i];
		}
		cout << max(dp[1][N], dp[2][N]) << endl;
	}
}