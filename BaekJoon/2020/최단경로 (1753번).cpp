#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int V, E;
int start;
vector<pair<int, int>> v[20001]; //v[a] = (b,c) : a부터 b까지 c의 거리
int dist[20001];

void dijk() {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q; //거리, 시작점, 최소힙으로 선언
	q.push({ 0, start });
	while (!q.empty()) {
		int x = q.top().second;
		int d = q.top().first;
		q.pop();
		
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int nd = v[x][i].second;
			if (dist[nx] > dist[x] + nd) {
				dist[nx] = dist[x] + nd;
				q.push({ dist[nx], nx });
			}
		}
	}
}

int main()
{
	cin >> V >> E >> start;
	for (int a,b,c,i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= V; i++)
		dist[i] = 987654321;
	dijk();

	for (int i = 1; i <= V; i++)
		if (dist[i] == 987654321)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	
}