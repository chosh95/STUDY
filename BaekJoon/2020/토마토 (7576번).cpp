#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, res;
int p[1002][1002];
int visit[1002][1002];
queue < pair<int, int>> q;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs()
{
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (p[nx][ny] == -1 || p[nx][ny] == 1)continue;
			if (visit[nx][ny] == 0) {
				q.push({ nx,ny });
				visit[nx][ny] = visit[x][y] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	res = 1;
	memset(visit, 0, sizeof(visit));
	cin >> M >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
			cin >> p[i][j];
			if (p[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	bfs();

	for (int i = 1; i <= N; i++) {
		if (res == -1) break;
		for (int j = 1; j <= M; j++) {
			if (p[i][j] == 0 && visit[i][j] == 0) { //익지 않은 토마토가 있으면 -1
				res = -1;
				break;
			}
			res = max(res, visit[i][j]);
		}
	}

	if (res == -1) cout << -1;
	else cout << res - 1;
}