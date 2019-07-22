#include <iostream>
#include <algorithm>
using namespace std;
int p[501][2];
int dp[501][501];
int N;

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i][0] >> p[i][1];
	}
	for (int i = 1; i <= N; i++) { //dp 차이 dp[1][1], dp[1][2], dp[1][3],...
		for (int j = 1; j <= N-i; j++) { //시작점 위치 dp[1][],dp[2][],...
			for (int k = j; k < j+i; k++) {
				int res = dp[j][k] + dp[k + 1][j + i] + p[j][0] * p[k][1] * p[j + i][1];
				if (dp[j][j + i] == 0 || dp[j][j+i] > res) dp[j][j + i] = res;
			}
		}
	}
	cout << dp[1][N];
}