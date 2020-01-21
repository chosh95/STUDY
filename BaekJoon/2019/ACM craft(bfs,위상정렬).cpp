#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, K, tmp, x, y, W;
vector<int> time,indegree,dist;
vector<vector<int> > p;
void bfs()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dist[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == W) {
			cout << dist[W] << "\n";
			return;
		}
		for (int &next : p[cur]) {
			if (--indegree[next] == 0) q.push(next);
			dist[next] = max(dist[next], dist[cur] + time[next]);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		time.clear();
		indegree.clear();
		dist.clear();
		p.clear();
		
		cin >> N >> K;

		dist.resize(N + 2);
		time.resize(N + 2);
		indegree.resize(N + 2);
		p.resize(N + 2);

		for (int i = 1; i <= N; i++) 
			cin >> time[i];
		
		for (int i = 1; i <= K; i++) {
			int x, y;
			cin >> x >> y;
			p[x].push_back(y);
			indegree[y]++;
		}
		cin >> W;
		bfs();
	}
}