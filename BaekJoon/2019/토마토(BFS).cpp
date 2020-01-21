#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int p[102][102][102]; // 가로,세로,높이
int N, M, H, res;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
int dz[3] = { -1,0,1 };

void bfs(int a, int b, int c)
{
	queue< pair< pair<int, int>, int> > q; //x,y,z,day
	q.push(make_pair(make_pair(a, b), c));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
				if (p[nx][ny][z] == 0) {
					q.push(make_pair(make_pair(nx, ny),z));
					p[nx][ny][z] = p[x][y][z] + 1;
				}
				else if (p[nx][ny][z] > p[x][y][z] + 1) {
					q.push(make_pair(make_pair(nx, ny), z));
					p[nx][ny][z] = p[x][y][z] + 1;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			int nz = z + dz[i];
			if (nz >= 1 && nz <= H) {
				if (p[x][y][nz] == 0) {
					q.push(make_pair(make_pair(x, y), nz));
					p[x][y][nz] = p[x][y][z] + 1;
				}
				else if (p[x][y][nz] > p[x][y][z] + 1) {
					q.push(make_pair(make_pair(x, y), nz));
					p[x][y][nz] = p[x][y][z] + 1;
				}
			}
		}
	}
}
void check()
{
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= N; k++) {
				if (p[j][k][i] == 0) {
					res = -1;
					return;
				}
				else if (p[j][k][i] >= res) res = p[j][k][i];
			}
		}
	}
}
int main()
{
	cin >> N >> M >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= N; k++) {
				cin >> p[j][k][i];
			}
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= N; k++) {
				if (p[j][k][i]==1) bfs(j, k, i);
			}
		}
	}
	check();
	if (res == -1) cout << res;
	else cout << res - 1;
}
