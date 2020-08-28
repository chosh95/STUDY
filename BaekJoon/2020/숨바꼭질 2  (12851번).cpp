#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, K;
int resTime = 987654321, resCnt = 0;
int visit[100001];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == K) {
			if (cost < resTime) {
				resTime = cost;
				resCnt = 1;
			}
			else if (cost == resTime) {
				resCnt++;
			}
			continue;
		}

		for (int nx : {cur - 1, cur + 1, cur * 2}) {
			if (nx < 0 || nx > 100000) continue;
			if (visit[nx] >= visit[cur] + 1) {
				q.push({ nx,cost + 1 });
				visit[nx] = cost + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) visit[i] = 987654321;
	bfs();

	cout << resTime << " " << resCnt;
}