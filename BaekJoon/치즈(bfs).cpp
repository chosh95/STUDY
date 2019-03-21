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
			if (visit[nx][ny]) continue;
			if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = 0;
					visit[nx][ny] = 1;
					a.push({ nx,ny });
				}
				else if (map[nx][ny] == 1) {
					map[nx][ny] = 0;
					visit[nx][ny] = 1;
					sum++;
				}
			}
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];
	int cheese = 0;
	while (true) {
		sum = 0;
		air();
		if (sum == 0) break;
		else {
			cheese = sum;
			res++;
		}
	}
	cout << res << "\n" << cheese;
}