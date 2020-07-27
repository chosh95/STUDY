#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M, res;
int dp[1001][1001][3];
int p[1001][1001];
int visit[1001][1001];
int dx[4] = { 0,0,1 };
int dy[4] = { -1,1,0 };

int dfs(int x, int y, int dir) {
	if (x == N && y == M) {
		return p[x][y];
	}
	if (dp[x][y][dir] != -INF) return dp[x][y][dir];

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny] != 0) continue;
		visit[nx][ny] = 1;
		dp[x][y][dir] = max(dp[x][y][dir], dfs(nx, ny, i) + p[x][y]);
		visit[nx][ny] = 0;
	}
	return dp[x][y][dir];
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> p[i][j];
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
		}
	visit[1][1] = 1;
	cout<<dfs(1, 1, 0);
}