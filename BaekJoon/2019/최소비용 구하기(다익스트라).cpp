#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
vector<pair<int, int>> adj[1001]; //adj[here] = { to, cost}
int N, M, A, B;
vector<int> dijkstra()
{
	vector<int> dist(N, INT_MAX);
	dist[A] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, A));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int ncost = adj[here][i].second + cost;
			if (dist[there] > ncost) {
				dist[there] = ncost;
				pq.push(make_pair(-ncost, there));
			}
		}
	}
	return dist;
}

int main()
{
	scanf("%d%d", &N, &M);
	N++;
	int from, to, cost;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &from, &to, &cost);
		adj[from].push_back(make_pair(to, cost));
	}
	scanf("%d%d", &A, &B);
	vector<int> ans = dijkstra();
	cout << ans[B];
}