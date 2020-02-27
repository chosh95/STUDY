#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N, res;
int p[102][102];
int visit[102][102];
int dist[102][102];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool isCoast(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>N || ny>N) continue;
		if (p[nx][ny] == 0) return true;
	}
	return false;
}

void bfs(int a, int b, int isl)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = isl;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (p[nx][ny] == 0 || visit[nx][ny] != 0) continue;
			q.push({ nx,ny });
			visit[nx][ny] = isl;
		}
	}
}

void bfs2(int a, int b, int isl) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	memset(dist, -1, sizeof(dist));
	dist[a][b] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visit[nx][ny] == isl) continue;
			if (p[nx][ny] == 1 && visit[nx][ny] != isl && dist[nx][ny]==-1) {
				res = min(res, dist[x][y]);
				return;
			}
			if (dist[nx][ny] == -1 && p[nx][ny] == 0) {
				if (dist[nx][ny] < dist[x][y] + 1)
					dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}


}
int main()
{
	res = 999999999;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> p[i][j];

	int island = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (p[i][j] == 1 && visit[i][j] == 0)
				bfs(i, j, island++);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (p[i][j] == 1 && isCoast(i,j))
				bfs2(i, j,visit[i][j]);

	cout << res;

}