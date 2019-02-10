#include <iostream>
#include <string>
using namespace std;
int R, C, m;
char c[25][25];
bool al[30];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
void dfs(int x, int y, int cnt)
{
	if (cnt >= m) 	m = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= R && ny <= C) {
			if (al[c[nx][ny] - 'A'] == true) continue;
			else {
				int a = c[nx][ny] - 'A';
				al[a] = true;
				dfs(nx, ny,cnt+1);
				al[a] = false;
			}
		}
		else continue;
	}
}
int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> c[i][j];
		}
	}
	al[c[1][1] - 'A'] = true;
	dfs(1, 1, 1);
	cout << m;
}

