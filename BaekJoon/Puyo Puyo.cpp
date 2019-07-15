#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
char p[13][7];
int visit[13][7];
int res, cnt, isclear;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int a, int b)
{
	queue < pair<int, int>> t;
	queue<pair<int, int>> q;
	visit[a][b] = 1;
	t.push({ a,b });
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx>12 || ny > 6) continue;
			if (visit[nx][ny] || p[nx][ny]!=p[x][y]) continue;
			q.push({ nx,ny });
			t.push({ nx,ny });
			visit[nx][ny] = ++cnt;
		}
	}
	if (cnt >= 4) {
		isclear = cnt;
		for (int i = 1; i <= cnt; i++) {
			p[t.front().first][t.front().second] = '.';
			t.pop();
		}
	}
}
void clear()
{
	for (int i = 1; i <= 6; i++) {
		for (int j = 11; j >= 1; j--) {
			if (p[j][i] == '.') continue;
			for (int k = 12; k > j; k--) {
				if (p[k][i] == '.') {
					p[k][i] = p[j][i];
					p[j][i] = '.';
					break;
				}
			}
		}
	}
}
int main()
{
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf(" %1c", &p[i][j]);
		}
	}
	while (true) {
		isclear = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				cnt = 1;
				if (visit[i][j]==0 && p[i][j]!='.') bfs(i, j);
			}
		}
		if (isclear<4) break;
		clear();
		res++;
	}
	cout << res;
}