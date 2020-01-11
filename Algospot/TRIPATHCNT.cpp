#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N;
int p[101][101];
int dp[101][101];
int cnt[101][101];
void path1(int x, int y)
{
	int& res = dp[x][y];
	if (res != -1) return;
	if (x == N) {
		res = p[x][y];
		return;
	}
	path1(x + 1, y);
	path1(x + 1, y + 1);
	res = p[x][y] + max(dp[x + 1][y], dp[x + 1][y + 1]);
	return;
}

int path2(int x, int y)
{
	if (x == N) return 1;
	int& res = cnt[x][y];
	if (res != -1) return res;
	res = 0;
	if (dp[x+1][y] == dp[x+1][y+1]) {
		return res = path2(x + 1, y) + path2(x + 1, y + 1);
	}
	else if (dp[x + 1][y] > dp[x + 1][y + 1]) {
		return res = path2(x + 1, y);
	}
	else return res = path2(x + 1, y + 1);
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		memset(p, -1, sizeof(p));
		memset(dp, -1, sizeof(dp));
		memset(cnt, -1, sizeof(cnt));
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= i; j++) 
				cin >> p[i][j];
		path1(1, 1);
		cout << path2(1, 1) << endl;
	}
}