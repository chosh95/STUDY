#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int p[26][26];
int visit[26][26];
int N;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
vector<int> res;

void bfs(int i, int j, int cnt) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visit[i][j] = 1;
	int Cnt = 2;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visit[nx][ny]) continue;
			if (p[nx][ny] == 0) continue;
			visit[nx][ny] = Cnt++;
			q.push({ nx,ny });
		}
	}
	res.push_back(Cnt-1);
}

int main()
{
	cin >> N;
	char a;
	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			if (a == '1')p[i][j] = 1;
			else p[i][j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (p[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j, cnt++);
			}
		}
	}

	sort(res.begin(), res.end());
	cout << cnt << "\n";
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
}