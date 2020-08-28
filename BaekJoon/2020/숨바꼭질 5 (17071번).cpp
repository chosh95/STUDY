#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
bool visit[500001][2];
int p[500001];
int res = 987654321;

void bfs() {
	queue<pair<int,int>> q;
	q.push({ N,0 });
	visit[N][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cost = q.front().second;
		q.pop();
		
		if (p[x] >= cost) {
			if (p[x] % 2 == cost % 2) {
				res = min(res, p[x]);
				continue;
			}
		}
		if (cost > res) continue;

		for (int nx : {x - 1, x + 1, x * 2}) {
			if (nx < 0 || nx > 500000) continue;
			if (visit[nx][(cost+1) % 2] == true) continue;
			q.push({ nx,cost + 1 });
			visit[nx][(cost + 1) % 2] = true;
		}
	}
}

int main()
{
	cin >> N >> K;

	memset(p, -1, sizeof(p));
	int tmpK = K;
	p[tmpK] = 0;
	for (int i = 1;; i++) {
		tmpK += i;
		if (tmpK > 500000) break;
		p[tmpK] = i;
	}

	memset(visit, false, sizeof(visit));

	bfs();

	if (res != 987654321)
		cout << res;
	else
		cout << -1;
}