#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <string>
using namespace std;
int N, M, res = 987654321;
int p[21][21]; // 0 : 빈곳, 1 : 벽
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int visit[21][21][21][21];

struct coin {
	int x1, y1, x2, y2;
	coin(int x1, int y1, int x2, int y2) {
		this->x1 = x1, this->y1 = y1, this->x2 = x2, this->y2 = y2;
	}
};

bool outOfBound(int x, int y) {
	if ( x < 1 || y < 1 || x > N || y > M) return true;
	return false;
}

bool isWall(int x, int y) {
	if (p[x][y] == 1) return true;
	return false;
}

void bfs(coin a) {
	queue<coin> q;
	q.push(a);

	while (!q.empty()) {
		coin cur = q.front();
		int x1 = cur.x1;
		int y1 = cur.y1;
		int x2 = cur.x2;
		int y2 = cur.y2;
		q.pop();
		if (visit[x1][y1][x2][y2] > 10) break;
		if (outOfBound(cur.x1, cur.y1) || outOfBound(cur.x2, cur.y2)) {
			res = visit[x1][y1][x2][y2];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx1 = x1 + dx[i];
			int ny1 = y1 + dy[i];
			int nx2 = x2 + dx[i];
			int ny2 = y2 + dy[i];
			if (outOfBound(nx1, ny1) && outOfBound(nx2, ny2)) continue;
			if (isWall(nx1, ny1) && isWall(nx2, ny2)) continue;
			if (isWall(nx1, ny1)) nx1 = x1, ny1 = y1;
			else if (isWall(nx2, ny2)) nx2 = x2, ny2 = y2;
			if (visit[nx1][ny1][nx2][ny2]) continue;
			visit[nx1][ny1][nx2][ny2] = visit[x1][y1][x2][y2] + 1;
			q.push(coin(nx1, ny1, nx2, ny2));
		}
	}
}

int main()
{
	int x1 = 0, x2 = 0, y1 = 0 , y2 = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char a;
			cin >> a;
			if (a == '.') p[i][j] = 0;
			else if (a == '#') p[i][j] = 1;
			else {
				if (x1 == 0) x1 = i, y1 = j;
				else x2 = i, y2 = j;
			}
		}
	}

	bfs(coin(x1,y1,x2,y2));

	if (res == 987654321) cout << "-1";
	else cout << res;
}