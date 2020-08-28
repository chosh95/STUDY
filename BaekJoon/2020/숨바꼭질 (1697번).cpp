#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
int res = 987654321;
bool visit[100001];

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (x == K) {
			res = cost;
			return;
		}

		for (int nx : {x - 1, x + 1, x * 2}) {
			if (nx < 0 || nx > 100000) continue;
			if (visit[nx] == true) continue;
			visit[nx] = true;
			q.push({ nx,cost + 1 });
		}
	}
}

int main()
{
	cin >> N >> K;

	bfs();

	cout << res;
}