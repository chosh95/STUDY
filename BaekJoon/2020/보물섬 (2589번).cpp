#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, res;
int p[53][53];
int visit[53][53];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int a, int b)
{
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > N || ny > M) continue;
			if (visit[nx][ny] != 0) continue;
			if (p[nx][ny] == 0) continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx,ny });
			res = max(res, visit[nx][ny]);
		}
	}
}

int main()
{
	cin >> N >> M;
	char a;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a;
			if (a == 'L') p[i][j] = 1;
			else p[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (p[i][j] == 1) bfs(i, j);

	cout << res - 1;
}