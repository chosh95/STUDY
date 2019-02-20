#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <memory.h>
#include <iostream>
using namespace std;
int p[502][502];
int dp[502][502];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int N, M;
int dfs(int x, int y)
{
	if (x == 1 && y == 1) return 1;
	if (x<1 || y<1 || x>N || y>M) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
			if (p[x][y] < p[nx][ny]) dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}


int main()
{
	cin >> N >> M;
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &p[i][j]);
	memset(dp, -1, sizeof(dp));
	dfs(N, M);
	cout << dp[N][M];
}