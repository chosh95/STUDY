#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int N, M, K;
long long dp[101][101];
map <pair<pair<int, int>, pair<int, int>>, int> m;

int main()
{
	cin >> N >> M >> K;

	int a, b, c, d;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c >> d;
		m[{ {min(a, c), min(b, d)}, { max(a,c),max(b,d) }}] = 1;
	}

	dp[0][0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 && j == 0) continue;
			if (i - 1 >= 0 && m[{ {i - 1, j}, { i,j }}] == 0)
				dp[i][j] += dp[i - 1][j];
			if (j - 1 >= 0 && m[{ {i, j - 1}, { i,j }}] == 0)
				dp[i][j] += dp[i][j - 1];
		}
	}

	cout << dp[N][M];
}