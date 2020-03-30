#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> p) {
	int answer = 0;

	dp[0][0] = p[0][0];
	for (int i = 1; i < p.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + p[i][j];
			if (j == i)
				dp[i][j] = dp[i - 1][j-1] + p[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + p[i][j];

			answer = max(answer, dp[i][j]);
		}
	}
	return answer;
}

int main()
{
	cout << solution({ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5 }});
}