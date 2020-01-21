#include <iostream>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int bx[4] = { 1,0,-1,0 };
int by[4] = { 0,-1,0,1 };
int p[51][51];
int N, M;
int ans;
void dfs(int x,int y,int d)
{
	if (p[x][y] == 1) return;
	if (p[x][y] == 0) {
		p[x][y] = 2;
		ans++;
	}
	for (int i = 0; i < 4; i++) {
		int nd = d - 1 < 0 ? 3 : d - 1;
		int nx = x + dx[nd], ny = y + dy[nd];
		if (p[nx][ny] == 0) {
			dfs(nx, ny, nd);
			return;	
		}
		else {
			d = nd;
		}
	}
	int nx = x + bx[d];
	int ny = y + by[d];
	dfs(nx, ny, d);
}

int main()
{
	ans = 0;
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			cin >> p[i][j];
	dfs(r, c, d);
	cout << ans;
}