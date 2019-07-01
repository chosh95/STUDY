#include <iostream>
#include <string>
#include <memory>
#include <queue>
using namespace std;
int N, M, res;
int p[1001][1001];
bool check[1001][1001][2];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

struct wall {
	int x, y, v, cnt;//x, y좌표, 벽 부셨는지 여부 0/1, 이동거리
};
void bfs()
{
	memset(check, false, sizeof(check));
	queue<wall> q;
	res = 99999999;
	check[1][1][0] = true;
	check[1][1][1] = true;
	q.push({ 1, 1, 0, 1 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int v = q.front().v;
		int cnt = q.front().cnt;
		q.pop();
		if (x == N && y == M) {
			if(res>cnt) res = cnt;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (check[nx][ny][v]) continue;
			if (p[nx][ny] == 0) {
				q.push({ nx,ny,v,cnt + 1 });
				check[nx][ny][v] = true;
			}
			if (p[nx][ny] == 1 && v==0) {
				q.push({ nx,ny,1,cnt + 1 });
				check[nx][ny][1] = true;
			}
		}
	}
}
int main()
{
	string c;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		for (int j = 1; j <= M; j++) {
			p[i][j] = c[j-1]-'0';
		}
	}
	bfs();
	if (res == 99999999) res = -1;
	cout << res;
}