#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const long long INF = 1000000000000;
int N, M, D, E;
long long height[100001];
long long asc[100001]; //등산 거리 기록
long long des[100001]; //하산 거리 기록
vector<pair<int, int>> adj[100001]; //adj[a] = (b,n) : a에서 b까지 n의 거리

void dijk(int start, long long visit[]) {
	priority_queue<pair<long long, int>,vector<pair<long long,int>>, greater<pair<long long,int>>> q;
	q.push({ 0,start }); // 시작지점에서 0의 거리로 출발
	visit[start] = 0;

	while (!q.empty()) {
		long long cost = q.top().first; //현재까지 이동 거리
		int cur = q.top().second; //현재 지점
		q.pop();

		if (cost > visit[cur]) continue; //중복 제거

		for (int i = 0; i < adj[cur].size(); i++) {
			long long nextDist = adj[cur][i].second; //다음 지점까지 거리
			int nextPos = adj[cur][i].first; //다음 이동 지점
			if (height[cur] >= height[nextPos]) continue;
			if (visit[nextPos] > cost + nextDist) {
				visit[nextPos] = cost + nextDist;
				q.push({ cost + nextDist,nextPos });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> D >> E;

	for (int i = 1; i <= N; i++) {
		cin >> height[i];
		asc[i] = des[i] = INF;
	}

	for (int i = 1; i <= M; i++) {
		int a, b, n;
		cin >> a >> b >> n;
		adj[a].push_back({ b,n });
		adj[b].push_back({ a,n });
	}

	dijk(1,asc); //1에서 등산하는 거리 기록
	dijk(N, des); //N에서 등산하는 거리 기록 -> 결과적으로 x에서 N으로 하산

	long long res = -INF;
	for (int i = 2; i < N; i++) {
		if (asc[i] == INF || des[i] == INF) continue; //등, 하산 불가 지점 제외
		long long cost = height[i] * E - D * (asc[i] + des[i]);
		res = max(cost, res);
	}

	if (res == -INF)
		cout << "Impossible";
	else
		cout << res;
}