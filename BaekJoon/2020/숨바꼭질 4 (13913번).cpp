#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
int visit[100001];
int res = 987654321;
vector<int> route;

void bfs() {
	queue<int> q;
	q.push({ N });
	visit[N] = 0;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K) {
			res = visit[x];
			return;
		}

		for (int nx : {x - 1, x + 1, x * 2}) {
			if (nx < 0 || nx > 100000) continue;
			if (visit[nx] > visit[x] + 1) {
				visit[nx] = visit[x] + 1;
				q.push({ nx });
			}
		}
	}
}

void trace() {
	queue<int> q;
	q.push(K);
	route.push_back(K);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		if (x == N)
			return;

		for (int nx : {x - 1, x + 1, x / 2}) {
			if (nx < 0 || nx>100000) continue;
			if (visit[nx] == visit[x] - 1) {
				q.push(nx);
				route.push_back(nx);
				break;
			}
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) visit[i] = 987654321;

	bfs();

	trace();

	cout << res << "\n";
	for (int i = route.size() - 1; i >= 0; i--) {
		cout << route[i] << " ";
	}
}