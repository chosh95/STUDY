#include <iostream>
using namespace std;
int p[501][501];
int v[501][501];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int N,res;

void dfs(int x, int y)
{
	v[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (p[nx][ny] > p[x][y]) {
				if (v[nx][ny] == 0) dfs(nx, ny);
				if(v[x][y]<v[nx][ny]+1) v[x][y] = v[nx][ny] + 1;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> p[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(v[i][j]==0) dfs(i, j);
			if (res < v[i][j]) res = v[i][j];
		}
	}
	cout << res;	
}