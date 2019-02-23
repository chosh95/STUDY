#include <iostream>
#include <queue>
using namespace std;
int N;
char p[102][102];
int v[102][102];
int v2[102][102];
int gres, nres;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int x, int y)
{
	v[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				if (p[x][y] == p[nx][ny] && v[nx][ny]==0) {
					v[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void gbfs(int x, int y)
{
	v[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				if (p[x][y] == p[nx][ny] && v2[nx][ny] == 0) {
					v2[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v[i][j] == 0) {
				bfs(i, j);
				nres += 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (p[i][j] == 'R') p[i][j] = 'G';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v2[i][j] == 0) {
				gbfs(i, j);
				gres += 1;
			}
		}
	}
	cout << nres << " " << gres;
}