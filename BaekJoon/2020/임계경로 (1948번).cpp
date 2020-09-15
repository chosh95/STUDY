#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<pair<int,int>> v[10001]; // v[a] = (b,c) : a부터 b까지 c거리
int visit[10001]; // a도시까지 가는 데 걸리는 거리 b
int indeg[10001]; // 위상
vector<pair<int,int>> parent[10001]; // i번째 도시에 갈 수 있는 이전 위치
int S, E; // 시작, 도착점
int cnt; // 방문한 다리 수 count
int way[10001]; // 다리 방문 여부

void bfs() {
	queue<int> q; // 현재 도시
	q.push(S);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextCost = v[cur][i].second;
			visit[next] = max(visit[next], visit[cur] + nextCost);
			if (--indeg[next] == 0) q.push(next);
		}
	}
}

void bfs_way(){
	queue<int> q;
	q.push(E);
	way[E] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < parent[cur].size(); i++) {
			int next = parent[cur][i].first;
			int nextDist = parent[cur][i].second;
			if (visit[next] == visit[cur] - nextDist) {
				cnt++;
				if (way[next] == 0) {
					way[next] = 1;
					q.push(next);
				}
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int a, b, c, i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		parent[b].push_back({ a,c });
		indeg[b]++;
	}
	cin >> S >> E;
	
	bfs();
	bfs_way();
	cout << visit[E] << "\n" << cnt;
}