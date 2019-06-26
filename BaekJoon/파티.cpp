#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, X;
vector<pair<int, int>> v[1001];
int cost[1001], cost2[1001];
int dijkstra(int start,int end)
{
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= N; i++) cost2[i] = 99999999;
	cost2[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = cost + v[x][i].second;
			if (ncost < cost2[nx]) {
				cost2[nx] = ncost;
				pq.push(make_pair(-ncost, nx));
			}
		}
	}
	return cost2[end];
}


int main()
{
	cin >> N >> M >> X;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= N; i++) {
		if (i != X) {
			cost[i] = dijkstra(i, X);
		}
	}
	dijkstra(X,1);
	int res = 0;
	for (int i = 1; i <= N; i++) {
		cost[i] += cost2[i];
		if (res < cost[i]) res = cost[i];
	}
	cout << res;
}