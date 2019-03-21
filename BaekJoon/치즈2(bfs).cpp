#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int R, C, res, sum;
int map[101][101];
int visit[101][101];
queue<pair<int, int>> q;
void air()
{
	queue<pair<int, int>> a;
	a.push({ 1,1 });
	memset(visit, 0, sizeof(visit));
	while (!a.empty()) {
		int x = a.front().first;
		int y = a.front().second;
		a.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[nx][ny]>1) continue;
			if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = 0;
					visit[nx][ny] = 2;
					a.push({ nx,ny });
				}
				else if (map[nx][ny] == 1 && visit[nx][ny]==0) {
					visit[nx][ny] = 1;
				}
				else if (map[nx][ny] == 1 && visit[nx][ny] == 1) {
					visit[nx][ny] = 2;
					map[nx][ny] = 0;
				}
			}
		}
	}
}
bool iszero()
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}
int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];
	while (true) {
		air();
		if (iszero()) break;
		else res++;
	}
	cout << res+1;
}