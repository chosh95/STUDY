#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, M;
int p[102][102];
int visit[102][102];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visit[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (visit[nx][ny] != 0 || p[nx][ny]!=1) continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx,ny });
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
			if (tmp == '1') p[i][j] = 1;
			else p[i][j] = 0;
		}
	}

	bfs();

	cout << visit[N][M];

}