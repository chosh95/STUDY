#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
char p[52][52];
int visit[52][52][4]; //x,y좌표에서 dir방향일 때의 거울 개수
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, ex, ey; //출구 좌표
struct mirror {
	int x, y, dir; //x,y 좌표, 방향 : 서, 동, 남, 북 
};
queue<mirror> q;
bool istrue(int x, int y, int dir)
{
	if (x<1 || x>N || y<1 || y>N) return false;
	return true;
}
void bfs()
{
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		if (x == ex && y == ey) {
			cout << visit[x][y][dir];
			return;
		}
		int nx = x + dx[dir], ny = y + dy[dir];
		while(istrue(nx,ny,dir) && p[nx][ny]=='.'){
			nx += dx[dir], ny += dy[dir];
		}
		if (istrue(nx,ny,dir) && p[nx][ny] == '!') {
			visit[nx][ny][dir] = visit[x][y][dir];
			q.push({ nx,ny,dir});
			int k = dir < 2 ? 2 : 0;
			for (int i = k; i < k + 2; i++) {
				if (visit[nx][ny][i] == -1) {
					visit[nx][ny][i] = visit[x][y][dir] + 1;
					q.push({ nx,ny,i });
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	memset(visit, -1, sizeof(visit));
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			scanf(" %1c", &p[i][j]);
			if (p[i][j] == '#') {
				if (q.empty()) {
					for (int k = 0; k < 4; k++) {
						q.push({ i,j,k });
						visit[i][j][k] = 0;
					}
				}
				else {
					ex = i, ey = j;
				}
				p[i][j] = '!';
			}
		}
	}
	bfs();
	return 0;
}