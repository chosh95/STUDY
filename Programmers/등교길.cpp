#include <string>
#include <iostream>
#include <vector>

using namespace std;
long long dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][0]][puddles[i][1]] = -1;
	}

	dp[1][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (dp[i][j] == -1) continue;
			if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1) continue;
			if (dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1];
			else if (dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 1000000007;
		}
	}

	answer = dp[m][n]; 
	return answer;
}

int main()
{
	cout << solution(4, 3, { {2,2} });
}