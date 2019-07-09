#include <iostream>
#include <queue>
using namespace std;
int N, R, C;
char p[100][100];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int visit[100][100]; // 0 : 방문 안한 상태, 1 : 당근 심은 상태, 2 : 당근 안심은 상태
void bfs()
{
	queue<pair<int, int>> q;
	q.push({ R,C });
	visit[R][C] = 1;
	p[R][C] = 'v';
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny < 1 || nx > N || ny > N) continue;
			if (visit[nx][ny] != 0) continue;
			q.push({ nx,ny });
			if (visit[x][y] == 1) {
				visit[nx][ny] = 2;
				p[nx][ny] = '.';
			}
			else {
				visit[nx][ny] = 1;
				p[nx][ny] = 'v';
			}
		}
	}
}

int main()
{
	cin >> N >> R >> C;
	bfs();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << p[i][j];
		}
		cout << "\n";
	}
}