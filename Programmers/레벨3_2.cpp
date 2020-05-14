#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	dp[1][1] = 1;

	for (int i = 0; i < puddles.size(); i++) {
		int x = puddles[i][1];
		int y = puddles[i][0];
		dp[x][y] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			if (dp[i][j] == -1) continue;
			int x = dp[i - 1][j];
			int y = dp[i][j - 1];
			if (x == -1) x = 0;
			if (y == -1) y = 0;
			dp[i][j] = (x + y) % 1000000007;
		}
	}
	answer = dp[n][m];
	return answer;
}

int main()
{
	cout << solution(4, 3, { {2,2} });
}