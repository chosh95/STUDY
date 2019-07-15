#include <iostream>
#include <cmath>
#include <memory.h>
#include <queue>
using namespace std;
int N, L, R;
int res, istrue;
int p[51][51];
int visit[51][51];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int a, int b)
{
	queue < pair<int, int>> q; // bfs용 큐
	queue < pair<int, int>> c; // 인구 이동 시킬 위치를 저장하는 큐
	visit[a][b] = 1;
	q.push({ a,b });
	c.push({ a,b });
	int cnt = 1, sum = p[a][b];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (visit[nx][ny])continue;
			int tmp = abs(p[x][y] - p[nx][ny]);
			if (tmp<L || tmp > R) continue;
			q.push({ nx,ny });
			c.push({ nx,ny });
			visit[nx][ny] = ++cnt;
			sum += p[nx][ny];
			if (cnt < visit[nx][ny]) cnt = visit[nx][ny];
		}
	}
	if (cnt != 1) {
		istrue = 1;
		int np = (int)(sum / cnt);
		for (int i = 1; i <= cnt; i++) {
			p[c.front().first][c.front().second] = np;
			c.pop();
		}
	}
}


int main()
{
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
	while (true) {
		istrue = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j] == 0) bfs(i, j);
			}
		}
		if (istrue == 0) break;
		res++;
	}
	cout << res;
}