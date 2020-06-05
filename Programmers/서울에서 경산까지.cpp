#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[101][100001]; 

int solution(int K, vector<vector<int>> t) {
	int answer = 0;
	dp[0][t[0][0]] = t[0][1];
	dp[0][t[0][2]] = t[0][3];
	for (int i = 1; i < t.size(); i++) {
		for (int j = 0; j <= K; j++) {
			if (dp[i - 1][j] == 0) continue;
			if (j + t[i][0] <= K) {
				dp[i][j + t[i][0]] = max(dp[i][j+t[i][0]],dp[i - 1][j] + t[i][1]);
				answer = max(answer, dp[i][j + t[i][0]]); 
			}
			if (j + t[i][2] <= K) {
				dp[i][j + t[i][2]] = max(dp[i][j+t[i][2]],dp[i - 1][j] + t[i][3]);
				answer = max(answer, dp[i][j + t[i][2]]);
			}
		}
	}
	return answer;
}

int main()
{
	cout << solution(3000, { { 1000,2000,300,700 }, { 1100,1900,400,900 }, { 900,1800,400,700 }, { 1200,2300,500,1200 } });
}