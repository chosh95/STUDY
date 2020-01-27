#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M, K;
int p[51][51];
int visit[51][51];
int res;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (p[nx][ny] == 1 && visit[nx][ny] == 0) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--) {
		//초기화
		memset(p, 0, sizeof(p));
		memset(visit, 0, sizeof(visit));
		res = 0;

		//입력
		cin >> N >> M >> K;
		for (int a, b, i = 0; i < K; i++) {
			cin >> a >> b;
			p[a][b] = 1;
		}

		//구현
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (p[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j);
					res++;
				}
			}
		}

		//출력
		cout << res << endl;
	}
}
