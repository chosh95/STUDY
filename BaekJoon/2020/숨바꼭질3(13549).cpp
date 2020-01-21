#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dist[100001];
int N, K;

void bfs()
{
	queue<int> q;
	q.push(N);
	dist[N] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == K) return;
		for (int nx : {x - 1, x + 1, 2 * x}) {
			if (nx < 0 || nx>100000) continue;
			if (dist[nx] > dist[x] + 1) {
				if (nx == 2 * x) dist[nx] = dist[x];
				else dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) dist[i] = 987654321;
	bfs();
	cout << dist[K];
}