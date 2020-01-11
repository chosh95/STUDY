#include <iostream>
using namespace std;
int C, N, M;
double dp[1001][2010];

double snail(int days, int dist)
{
	if (days == M) return dist >= N ? 1 : 0;
	double& res = dp[days][dist];
	if (res != -1.0) return res;
	return res = (0.25 * snail(days + 1, dist + 1) + 0.75 * snail(days + 1, dist + 2));
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M*2+2; j++) {
				dp[i][j] = -1.0;
			}
		}
		cout.precision(11);
		cout << snail(0, 0) << endl;
	}
	return 0;
}