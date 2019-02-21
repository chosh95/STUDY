#include <iostream>
#include <queue>
using namespace std;
int p[52][52];
int visit[52][52];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
queue<pair<int, int>> q;

void bfs(int fx,int fy)
{
	q.push(make_pair(fx, fy));
	visit[fx][fy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (p[nx][ny] == 1 && visit[nx][ny] != 1) {
				q.push(make_pair(nx, ny));
				visit[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int M, N, K;
		cin >> M >> N >> K;
		int m, n;

		for (int i = 0; i <= 51; i++) //행렬 초기화
			for (int j = 0; j <= 51; j++) {
				p[i][j] = 0;
				visit[i][j] = 0;
			}

		for (int i = 1; i <= K; i++) { //p행렬 값 받기
			cin >> m >> n;
			p[n][m] = 1;
		}

		int count = 0; // 필요한 지렁이 수 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (p[i][j] == 1 && visit[i][j] != 1) {
					count++;
					bfs(i,j);
				}
			}
		}
		cout << count << endl;
	}
}