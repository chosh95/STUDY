#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int N, M, rx, ry, bx ,by, res;
char map[11][11];
int visit[11][11][11][11];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {rx,ry},{bx,by} });
	visit[rx][ry][bx][by] = 1;
	res = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int rrx = q.front().first.first;
			int rry = q.front().first.second;
			int bbx = q.front().second.first;
			int bby = q.front().second.second;
			q.pop();
			if (map[rrx][rry] == 'O' && map[rrx][rry] != map[bbx][bby]) {
				return;
			}
			for (int i = 0; i < 4; i++) {
				int nrx = rrx, nry = rry, nbx = bbx, nby = bby;
				while (map[nrx + dx[i]][nry + dy[i]] != '#' && map[nrx][nry] != 'O') {
					nrx += dx[i];
					nry += dy[i];
				}
				while (map[nbx + dx[i]][nby + dy[i]] != '#' && map[nbx][nby] != 'O') {
					nbx += dx[i];
					nby += dy[i];
				}
				if (nrx == nbx && nry == nby) {
					if (map[nrx][nry] == 'O') continue;
					if (abs(nrx - rrx) + abs(nry - rry) < abs(bbx - nbx) + abs(bby - nby)) {
						nbx -= dx[i];
						nby -= dy[i];
					}
					else {
						nrx -= dx[i];
						nry -= dy[i];
					}
				}
				if (visit[nrx][nry][nbx][nby]) continue;
				q.push({ {nrx,nry},{nbx,nby} });
				visit[nrx][nry][nbx][nby] = 1;
			}
		}
		if (res == 10) {
			res = -1;
			return;
		}
		res++;
	}
	res = -1;
	return;
}


int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'R') rx = i, ry = j;
			else if (map[i][j] == 'B') bx = i, by = j;
		}
	}
	bfs();
	cout << res;
}