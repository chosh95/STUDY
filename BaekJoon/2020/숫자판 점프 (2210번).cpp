#include <iostream>
using namespace std;
int p[6][6];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int visit[1000000];
int res;

void dfs(int x, int y, int sum, int cnt) {

	if (cnt == 5) {
		if (visit[sum] == 0) {
			visit[sum] = 1;
			res++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx>5 || ny>5) continue;
		dfs(nx, ny, sum * 10 + p[nx][ny], cnt + 1);
	}
}

int main()
{
	for (int i = 1; i <= 5; i++) 
		for (int j = 1; j <= 5; j++) 
			cin >> p[i][j];
	
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			dfs(i, j, p[i][j], 0);

	cout << res;
}