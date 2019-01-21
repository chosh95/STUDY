#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
int p[1002][1002];
int dist[1002][1002];
queue<pair<int, int> > q;

void bsf(int n, int m)
{
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if ((dist[nx][ny] == 0 || dist[nx][ny] > dist[x][y] + 1) && p[nx][ny] != -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main()
{
	int M, N;
	cin >> M >> N;

	for (int i = 0; i <= M; i++) {
		p[0][i] = -1;
		p[N + 1][i] = -1;
		dist[0][i] = -1;
		dist[N + 1][i] = -1;
	}
	for (int j = 1; j <= N; j++) {
		p[j][0] = -1;
		p[j][M + 1] = -1;
		dist[j][0] = -1;
		dist[j][M + 1] = -1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> p[i][j];
			if (p[i][j] == 1) {
				q.push(make_pair(i, j));
				dist[i][j] = 1;
			}
			else if (p[i][j] == -1) dist[i][j] = -1;
		}
	}

	if (q.empty()) cout << 0;
	else {
		bsf(N, M);
		int maxx = 1;
		bool tmp = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (dist[i][j] == 0) {
					tmp = true;
					break;
				}
				else if (dist[i][j] > maxx) maxx = dist[i][j];
			}
			if (tmp) break;
		}
		if (tmp) cout << -1;
		else if (maxx == 1) cout << 0;
		else cout << maxx - 1;
	}
}