#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N, M, res=0;
int p[501][501];
int visit[501][501];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
void dfs(int x, int y, int cnt, int sum)
{
	if (cnt == 4) {
		if (res < sum) res = sum;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (visit[nx][ny]==0) {
					visit[nx][ny] = 1;
					dfs(nx, ny, cnt + 1, sum + p[x][y]);
					visit[nx][ny] = 0;
				}
			}
		}
	}
}
void check()
{
	//で
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int tmp = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i - 1][j + 1];
			if (res < tmp) res = tmp;
		}
	}
	//ぬ
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int tmp = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 1];
			if (res < tmp) res = tmp;
		}
	}
	//た
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 1][j + 1];
			if (res < tmp) res = tmp;
		}
	}
	//っ
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 2; j <= M; j++) {
			int tmp = p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 1][j - 1];
			if (res < tmp) res = tmp;
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visit[i][j] = 1;
			dfs(i, j, 0, 0);
			visit[i][j] = 0;
		}
	}
	check();
	cout << res;
}