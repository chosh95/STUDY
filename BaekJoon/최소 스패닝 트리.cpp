#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E;
vector<pair<int, int>> adj[10001]; //p[i][j] = i에서 j로 가는 가중치
int visit[10001];
priority_queue <pair<int, int>> q; //cost,node
int main()
{
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	q.push({ 0,1 });
	int cost = 0;
	while (!q.empty()) {
		int c = q.top().first;
		int n = q.top().second;
		q.pop();
		if (visit[n] == 1) continue;
		visit[n] = 1;
		cost += -c;
		for (pair<int,int> p: adj[n]){
			int nc = p.second;
			int nn = p.first;
			q.push(make_pair(-nc, nn));
		}
	}
	cout << cost;
}