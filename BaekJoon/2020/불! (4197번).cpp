#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
int N, M, res = 987654321;
int p[1001][1001]; // 0 : 지나갈 수 있음, 1 : 벽 또는 불
int visit[1001][1001];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int jx, jy;
queue<pair<int, int>> q;

void bfs() {
	q.push({ jx,jy });
	visit[jx][jy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (p[x][y] == 0 && (x == 1 || x == N || y == 1 || y == M)) {
			res = visit[x][y];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny < 1 || nx>N || ny>M) continue;
			if (p[nx][ny] == 1) continue;
			if (visit[nx][ny] == -1) {
				visit[nx][ny] = visit[x][y] + 1;
				p[nx][ny] = p[x][y];
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	memset(visit, -1, sizeof(visit));

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			if (str[j - 1] == '#')
				p[i][j] = 1;
			else if (str[j - 1] == 'F') {
				p[i][j] = 1;
				q.push({ i,j });
				visit[i][j] = 0;
			}
			else if (str[j - 1] == 'J') {
				p[i][j] = 0;
				jx = i, jy = j;
			}
			else
				p[i][j] = 0;
		}
	}

	bfs();

	if (res == 987654321)
		cout << "IMPOSSIBLE";
	else
		cout << res;
}