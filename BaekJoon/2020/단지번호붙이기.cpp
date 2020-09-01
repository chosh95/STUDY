#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
int p[30][30];
int visit[30][30];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int res = 1;
vector<int> house;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });

	int cnt = 1;
	visit[a][b] = cnt;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <1 || ny<1 || nx > N || ny>N) continue;
			if (visit[nx][ny] != 0) continue;
			if (p[nx][ny] == 0) continue;
			visit[nx][ny] = ++cnt;
			q.push({ nx,ny });
		}
	}
	house.push_back(cnt);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++) {
			p[i][j] = str[j-1] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (p[i][j] == 1 && visit[i][j] == 0)
				bfs(i, j);
		}
	}

	sort(house.begin(), house.end());
	cout << house.size() << "\n";
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << "\n";
	}
}