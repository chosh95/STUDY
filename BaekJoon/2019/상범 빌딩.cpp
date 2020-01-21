#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

char map[31][31][31];
int visit[31][31][31];
int L, R, C;
int sx, sy, sz, ex, ey, ez;
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { -1,0,0,1,0,0 };
int dz[6] = { 0,1,-1,0,0,0 };

void bfs()
{
	memset(visit, -1, sizeof(visit));
	queue<pair<pair<int, int>, int >> q;
	q.push({ {sx,sy},sz });
	visit[sx][sy][sz] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		if (x == ex && y == ey && z == ez) return;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx<1 || nx>L || ny<1 || ny > R || nz<1 || nz>C) continue;
			if (map[nx][ny][nz] == '#') continue;
			if (visit[nx][ny][nz] == -1 || visit[nx][ny][nz] > visit[x][y][z] + 1) {
				visit[nx][ny][nz] = visit[x][y][z] + 1;
				q.push({ {nx,ny},nz });
			}
		}
	}
}

int main()
{
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				string s;
				cin >> s;
				for (int k = 1; k <= C; k++) {
					map[i][j][k] = s[k - 1];
					if (map[i][j][k] == 'S') {
						sx = i, sy = j, sz = k;
					}
					if (map[i][j][k] == 'E') {
						ex = i, ey = j, ez = k;
					}
				}
			}
		}
		bfs();
		if (visit[ex][ey][ez] == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << visit[ex][ey][ez] << " minute(s).\n";
	}
	return 0;
}