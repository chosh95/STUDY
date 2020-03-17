#include <iostream>
#include <algorithm>
using namespace std;
int R, C, K, res;
int p[10][10];
int visit[10][10];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void dfs(int x, int y, int dist) {
	
	if (x == 1 && y == C) {
		if (dist == K) res++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>R || ny>C) continue;
		if (visit[nx][ny]) continue;
		if (p[nx][ny] == 1) continue;
		visit[nx][ny] = 1;
		dfs(nx, ny, dist+1);
		visit[nx][ny] = 0;
	}
}

int main()
{
	cin >> R >> C >> K;
	char a;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> a;
			if (a == '.') p[i][j] = 0;
			else p[i][j] = 1;
		}
	}
	visit[R][1] = 1;
	dfs(R, 1, 1);

	cout << res;
}