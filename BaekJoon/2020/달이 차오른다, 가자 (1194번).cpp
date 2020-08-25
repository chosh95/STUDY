#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M;
int p[51][51]; // 0 : 이동가능, 1 : 탈출구, 2 : 벽, 10~15 : A~F, 100~105 : a~f
int visit[51][51][1<<6];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int sx, sy; //시작 위치
int res = 987654321; // 결과값

struct pos {
	int x, y, dist; // 좌표, 이동거리
	int key = 0; // 열쇠 소유 여부 [A,B, ... , F]
};

void bfs() {
	memset(visit, -1, sizeof(visit));
	queue<pos> q;
	q.push({ sx,sy,0, 0 });
	visit[sx][sy][0] = 0;
	
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (p[cur.x][cur.y] == 1) {
			res = min(res, visit[cur.x][cur.y][cur.key]);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue; // 범위 벗어나면 continue
			if (p[nx][ny] == 2) continue; // 벽이면 건너갈 수 없다.
			if (p[nx][ny] == 0 || p[nx][ny] == 1) {
				if (visit[nx][ny][cur.key] != -1) continue;
				q.push({ nx,ny,cur.dist + 1,cur.key });
				visit[nx][ny][cur.key] = cur.dist + 1;
			}
			else if (p[nx][ny] >= 10 && p[nx][ny] <= 15) { // 문
				int needKey = 1<<(p[nx][ny] - 10); // 문을 여는데 필요한 열쇠 인덱스
				if ((cur.key & needKey) == 0) continue; //열쇠 없으면 못간다.
				if (visit[nx][ny][cur.key | needKey] != -1) continue; // 이미 방문했으면 continue
				q.push({ nx,ny,cur.dist + 1,cur.key|needKey });
				visit[nx][ny][cur.key | needKey] = cur.dist + 1;
			}
			else { // 열쇠
				int nextKey = 1<<(p[nx][ny] - 100);
				if (visit[nx][ny][cur.key | nextKey] != -1) continue;
				q.push({ nx,ny,cur.dist + 1,cur.key|nextKey });
				visit[nx][ny][cur.key|nextKey] = cur.dist + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			char cur = str[j - 1];
			if (cur == '.')
				p[i][j] = 0;
			else if (cur == '#')
				p[i][j] = 2;
			else if (cur == '0') {
				sx = i, sy = j;
				p[i][j] = 0;
			}
			else if (cur == '1') {
				p[i][j] = 1;
			}
			else if (cur >= 'A' && cur <= 'F')
				p[i][j] = cur - 'A' + 10;
			else
				p[i][j] = cur - 'a' + 100;
		}
	}

	bfs();

	if (res == 987654321)
		cout << -1;
	else
		cout << res;
}