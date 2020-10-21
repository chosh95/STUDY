#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;
int N, M;
vector<pair<int,int>> p[101][101];
int light[101][101];
int visit[101][101];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	light[1][1] = 1;
	visit[1][1] = 1;

	bool isLight = false;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < p[x][y].size(); i++) {
			int nx = p[x][y][i].first;
			int ny = p[x][y][i].second;
			if (light[nx][ny]) continue;
			light[nx][ny] = 1;
			isLight = true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (light[nx][ny] == 0) continue;
			if (visit[nx][ny] == 1) continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	return isLight;
}

int main()
{
	cin >> N >> M;
	for (int a,b,x,y,i = 1; i <= M; i++) {
		cin >> a >> b >> x >> y;
		p[a][b].push_back({ x,y });
	}

	while (true) {
		memset(visit, 0, sizeof(visit));
		if (!bfs()) break;
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (light[i][j] == 1) res++;
		}
	}

	cout << res;
}