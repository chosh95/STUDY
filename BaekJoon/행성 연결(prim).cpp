#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int visit[1001];
vector<pair<int, int>> adj[1001]; // 가는 노드 번호, cost  ex) adj[1] = {2,10}이면
								  //  1번 노드에서 2번노드로 가는 비용이 10이란 뜻
priority_queue<pair<int, int>> q; // cost, 노드번호

int main()
{
	int N, a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a);
			if (i == j) continue;
			adj[i].push_back(make_pair(j, a));
			adj[j].push_back(make_pair(i, a));
		}
	}
	q.push({ 0,1 });
	long long ans = 0;
	while (!q.empty()) {
		int cost = q.top().first;
		int node = q.top().second;
		q.pop();
		if (visit[node] == 1) continue;
		visit[node] = 1;
		ans += -cost;
		for (pair<int, int> p : adj[node]) {
			int toCost = p.second;
			int toNode = p.first;
			q.push(make_pair(-toCost, toNode));
		}
	}
	cout << ans;
}