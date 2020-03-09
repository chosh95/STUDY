#include <iostream>
#include <queue>
using namespace std;
int N, M, res;
int p[101][101];
int visit[101][101];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs()
{
	queue<pair<int, int>> q; 
	q.push({ 1,1 });
	visit[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx >N || ny>M) continue;
			if (p[nx][ny] == 1) {
				if (visit[nx][ny] > visit[x][y] + 1) {
					visit[nx][ny] = visit[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else if(p[nx][ny]==0){
				if (visit[nx][ny] > visit[x][y]) {
					visit[nx][ny] = visit[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}

}
int main()
{
	cin >> M >> N;
	char a;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> a;
			if (a == '1') p[i][j] = 1;
			else p[i][j] = 0;
			visit[i][j] = 9999;
		}

	bfs();

	cout << visit[N][M];
}