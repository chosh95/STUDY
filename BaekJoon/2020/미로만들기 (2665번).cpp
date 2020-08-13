#include <iostream>
#include <memory.h>
#include <queue>
#include <string>
using namespace std;
int N;
int p[51][51];
int visit[51][51];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	memset(visit, -1, sizeof(visit));
	visit[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx > N || ny>N) continue;
			if (p[nx][ny] == 1) { //다음 방이 흰 방인 경우
				if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y]) {
					visit[nx][ny] = visit[x][y];
					q.push({ nx,ny });
				}
			}
			else { //다음 방이 검은 방인 경우
				if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + 1) {
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
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
			p[i][j+1] = str[j]-'0';
	}

	bfs();

	cout << visit[N][N];
}