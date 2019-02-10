#include <iostream>
#include <queue>
using namespace std;
int p[10][10];
int c[10][10];
int t[10][10];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int N, M;
int ans;
void virus()
{
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
			t[i][j] = c[i][j];
			if (t[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= M) {
				if (t[nx][ny] == 0) {
					t[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void countsafe()
{
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (t[i][j] == 0) tmp++;
		}
	}
	if (tmp > ans) ans = tmp;
}
void dfs(int cnt)
{
	if (cnt == 3) {
		virus();
		countsafe();
		return;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (c[i][j] == 0) {
				c[i][j] = 1;
				dfs(cnt + 1);
				c[i][j] = 0;
			}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++)
			cin >> p[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			c[i][j] = p[i][j];

	dfs(0);
	cout << ans;
}