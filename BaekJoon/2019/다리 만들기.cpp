#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int N, cnt, res=9999999999;
int map[101][101];
int visit[101][101];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
bool isCoast(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>N || ny>N) continue;
		if (map[nx][ny] == 0) return true;
	}
	return false;
}
void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	map[a][b] = ++cnt;
	visit[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visit[nx][ny] == 0 && map[nx][ny] != 0) {
				q.push({ nx,ny });
				map[nx][ny] = cnt;
				visit[nx][ny] = 1;
			}
		}
	}
}

void dist(int a, int b, int color)
{
	queue<pair<int, int>> q;
	memset(visit, -1, sizeof(visit));
	visit[a][b] = 0;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (map[nx][ny] == color) continue;
			if (visit[nx][ny] == -1 && map[nx][ny] != color && map[nx][ny]!=0) {
				if (res > visit[x][y]) {
					res = visit[x][y];
					return;
				}
			}
			if (visit[nx][ny] == -1 && map[nx][ny] == 0) {
				if (visit[nx][ny] < visit[x][y] + 1){
					visit[nx][ny] = visit[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) 
			cin >> map[i][j];

	//섬마다 coloring
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) bfs(i, j);
		}
	}
	//섬의 바닷가쪽이면 가장 가까운 섬과의 거리 측정
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] != 0 && isCoast(i, j)) 
				dist(i, j, map[i][j]);
		}
	}

	cout << res;
}