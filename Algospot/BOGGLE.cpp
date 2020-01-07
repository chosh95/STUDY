#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int C, N;
string res;
char p[6][6];
bool isTrue;
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int memo[6][6][11];
void dfs(int x, int y, int cnt) {
	if (p[x][y] != res[cnt]) return;
	if (res.length() == cnt + 1) {
		isTrue = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx >5 || ny < 1 || ny>5) continue;
		if (p[nx][ny] != res[cnt + 1]) continue;
		if (memo[nx][ny][cnt + 1] == 1) continue;
		memo[nx][ny][cnt + 1] = 1;
		dfs(nx, ny, cnt + 1);
	}
}
int main()
{
	cin >> C;
	while (C--) {
		for (int i = 1; i < 6; i++) {
			string str;
			cin >> str;
			for (int j = 1; j < 6; j++) {
				p[i][j] = str[j - 1];
			}
		}
		cin >> N;
		while (N--) {
			memset(memo, 0,sizeof(memo));
			cin >> res;
			isTrue = false;
			for (int i = 1; i <= 5; i++) {
				if (isTrue) break;
				for (int j = 1; j <= 5; j++) {
					if (p[i][j] == res[0]) {
						memo[i][j][0] = 1;
						dfs(i, j, 0);
					}
					else continue;
				}
			}
			cout << res;
			if (isTrue) cout << " YES\n";
			else cout << " NO\n";
		}
	}
}