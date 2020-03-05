#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, res;
char p[21][21];
vector<char> v;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool isPossible(int x, int y) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == p[x][y]) return false;
	}
	return true;
}

void dfs(int x, int y, int cnt)
{
	res = max(res, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
		if (!isPossible(nx, ny)) continue;
		v.push_back(p[nx][ny]);
		dfs(nx, ny, cnt + 1);
		v.pop_back();
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= C; j++) 
			cin >> p[i][j];

	v.push_back(p[1][1]);
	dfs(1, 1, 1);

	cout << res;
}