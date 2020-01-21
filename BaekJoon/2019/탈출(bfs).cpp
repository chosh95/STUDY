#include <iostream>
#include <queue>
using namespace std;
int R, C, res;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
char map[51][51];
int watermap[51][51];
bool visit[51][51];
queue<pair<int, int>> waterq;
queue<pair<pair<int, int>, int>> q;

void water()
{
	while(!waterq.empty()) {
		int x = waterq.front().first;
		int y = waterq.front().second;
		waterq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>R || ny>C) continue;
			if (map[nx][ny] == '.' && watermap[nx][ny]==0) {
				watermap[nx][ny] = watermap[x][y] + 1;
				waterq.push({ nx,ny });
			}
		}
	}
}
void bfs()
{
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int num = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 'D') {
				res = num + 1;
				return;
			}
			if (visit[nx][ny] == true) continue;
			if (nx<1 || ny<1 || nx>R || ny>C) continue;
			if (map[nx][ny] == '.' && (watermap[nx][ny]==0 ||watermap[nx][ny] > num + 1)) {
				visit[nx][ny] = true;
				q.push({ {nx,ny},num + 1 });
			}
		}
	}
}
int main()
{
	cin >> R >> C;
	int a, b;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				waterq.push({ i,j });
			}
			else if (map[i][j] == 'S') {
				q.push({ {i,j},0 });
				visit[i][j] = true;
			}
		}
	}
	water();
	bfs();

	if (res == 0) cout << "KAKTUS";
	else cout << res;
	
}