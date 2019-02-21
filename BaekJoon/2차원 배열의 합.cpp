#include <iostream>
using namespace std;
int p[301][301];
int dp[301][301];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> p[i][j];
	int K;
	cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + p[i][j];
		}
	}

	for (int i = 1; i <= K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a-1][b-1] << endl;
	}

}