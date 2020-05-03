#include <iostream>
#include <queue>
using namespace std;
int T, N;
int p[130][130];
int visit[130][130];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visit[1][1] = p[1][1];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visit[nx][ny] > visit[x][y] + p[nx][ny]) {
				visit[nx][ny] = visit[x][y] + p[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	int iter = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> p[i][j];
				visit[i][j] = 987654321;
			}
		}
		bfs();
		cout << "Problem " << iter++ << ": " <<visit[N][N]<< "\n";
	}
}
