#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int V,maxPos,res;
vector<pair<int, int>> adj[100001];
int visit[100001];

void bfs(int cur)
{
	memset(visit, -1, sizeof(visit));
	queue<int> q;
	q.push(cur);
	visit[cur] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int nx = adj[x][i].first;
			int dist = adj[x][i].second;
			if (visit[nx] != -1) continue;
			q.push(nx);
			visit[nx] = visit[x] + dist;
			if (visit[nx] > res) {
				res = visit[nx];
				maxPos = nx;
			}
		}

	}
}



int main()
{
	cin >> V;
	for (int cur, a, b, i = 1; i <= V; i++) {
		cin >> cur;
		while (true) {
			cin >> a;
			if (a == -1) break;
			cin >> b;
			adj[cur].push_back({ a,b });
		}
	}

	bfs(1);
	bfs(maxPos);
	cout << res;
}
