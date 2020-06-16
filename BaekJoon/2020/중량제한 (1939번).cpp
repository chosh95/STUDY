#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int,int>> bridge[10001];

int N, M;
int start, dest;
int maxW, res;
int visit[10001];

int bfs(int mid) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == dest) return 1;
		for (int i = 0; i < bridge[cur].size(); i++) {
			int next = bridge[cur][i].first;
			int nextW = bridge[cur][i].second;
			if (visit[next] == 1 || nextW < mid) continue;
			visit[next] = 1;
			q.push(next);
		}
	}
	return 0;
}

void binary() {
	int hi = maxW, lo = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		memset(visit, 0, sizeof(visit));
		if (bfs(mid) == 1)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	cout << hi;
}

int main()
{
	cin >> N >> M;
	for (int a, b, c, i = 0; i < M; i++) {
		cin >> a >> b >> c;
		bridge[a].push_back({ b,c });
		bridge[b].push_back({ a,c });
		maxW = max(maxW, c);
	}
	cin >> start >> dest;

	binary();
}
