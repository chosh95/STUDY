#include <iostream>
#include <memory.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int res = 987654321;
int p[1001][1001];
bool visit[1001][1001][11];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

struct pos {
	int x, y, cnt, dis;
};

void bfs() {
	queue<pos> q;
	q.push({ 1,1,0,1 });
	visit[1][1][0] = true;
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int dis = q.front().dis;
		q.pop();

		if (x == N && y == M) {
			res = dis;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (visit[nx][ny][cnt] == false) {
				if (p[nx][ny] == 1) {
					if (cnt + 1 > K) continue;
					q.push({ nx,ny,cnt + 1,dis + 1 });
					visit[nx][ny][cnt + 1] = true;
				}
					
				else {
					q.push({ nx,ny,cnt,dis + 1 });
					visit[nx][ny][cnt] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			p[i][j] = str[j - 1] - '0';
		}
	}

	bfs();

	if (res == 987654321)
		cout << -1;
	else
		cout << res;
}