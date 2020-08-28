#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
int visit[100001];
int res = 987654321;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == K) {
			res = min(res, cost);
			continue;
		}

		for (int nx : {cur - 1, cur + 1, cur * 2}) {
			if (nx < 0 || nx > 100000) continue;
			int nextCost = cost;
			if (nx != cur * 2) nextCost += 1;
			if (visit[nx] > nextCost) {
				q.push({ nx,nextCost });
				visit[nx] = nextCost;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) visit[i] = 987654321;


	bfs();

	cout << res;
}