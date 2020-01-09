#include <iostream>
#include <memory.h>
using namespace std;
int C, N;
int p[101][101];
int dp[101][101];
void jump(int x, int y)
{
	if (x == N && y == N) return;

	if (x + p[x][y] <= N && dp[x+p[x][y]][y]==0) {
		dp[x+p[x][y]][y] = 1;
		jump(x + p[x][y], y);
	}
	if (y + p[x][y] <= N && dp[x][y+p[x][y]]==0) {
		dp[x][y+p[x][y]] = 1;
		jump(x, y + p[x][y]);
	}
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) 
				cin >> p[i][j];
		dp[1][1] = 0;
		jump(1, 1);
		if (dp[N][N] == 0) cout << "NO\n";
		else cout << "YES\n";
	}
}