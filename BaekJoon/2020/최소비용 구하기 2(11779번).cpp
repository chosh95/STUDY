#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int start, target, res = 987654321;
vector<pair<int,int>> v[1001]; //v[i] = {j,k} : i에서 j까지 거리 k
int dist[1001]; // dist[i] = start에서 i까지 최소 거리
int route[1001]; // route[i] = 경로에서 i 노드로 가기 바로 직전 노드

void dijkstra() {
	priority_queue<pair<int, int>> q;
	dist[start] = 0;
	q.push({ 0,start });// -거리, 노드
	while (!q.empty()) {
		int cur = q.top().second;
		int curD = -q.top().first;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextD = v[cur][i].second;
			if (dist[next] > curD + nextD) {
				dist[next] = curD + nextD;
				route[next] = cur;
				q.push({ -dist[next],next });
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int here,there,distance, i = 1; i <= M; i++) {
		cin >> here >> there >> distance;
		v[here].push_back({ there,distance });
	}
	cin >> start >> target;

	for (int i = 1; i <= N; i++) dist[i] = 987654321;
	dijkstra();
	cout << dist[target]<<"\n";

	vector<int> ans;
	int idx = target;
	while (idx) {
		ans.push_back(idx);
		idx = route[idx];
	}

	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}