#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int p[21][21];
int visit[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
vector<pair<int, int>> zeroPos;

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;
	int cnt = 0;
	bool isPossible = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (visit[nx][ny] == 1) continue;
			if (p[nx][ny] == 0) isPossible = false;
			else if (p[nx][ny] == 1) continue;
			else if (p[nx][ny] == 2) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
	if (!isPossible) return 0;
	return cnt;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) {
			cin >> p[i][j];
			if (p[i][j] == 0) zeroPos.push_back({ i,j });
		}

	int res = 0;

	for (int i = 0; i < zeroPos.size(); i++) {
		for (int j = i + 1; j < zeroPos.size(); j++) {
			p[zeroPos[i].first][zeroPos[i].second] = 1;
			p[zeroPos[j].first][zeroPos[j].second] = 1;

			int cnt = 0;
			memset(visit, 0, sizeof(visit));
			for (int a = 1; a <= N; a++) {
				for (int b = 1; b <= M; b++) {
					if (p[a][b] == 2 && visit[a][b] == 0) {
						cnt += bfs(a, b);
					}
				}
			}
			res = max(res, cnt);


			p[zeroPos[i].first][zeroPos[i].second] = 0;
			p[zeroPos[j].first][zeroPos[j].second] = 0;
		}
	}

	cout << res;
}