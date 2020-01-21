#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int p[52][52];
int v[52][52];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int N, M, res = 0;
void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	memset(v, 0, sizeof(v));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (p[nx][ny] == 1 && v[nx][ny]==0) {
					v[nx][ny] = v[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				if (v[nx][ny] > res) res = v[nx][ny];
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	char tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			if (tmp == 'W') p[i][j] = 0;
			else p[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (p[i][j] == 1) {
				bfs(i, j);
			}
		}
	}
	cout << res;
}