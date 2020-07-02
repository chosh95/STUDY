#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, X, res;
vector<pair<int, int>> v[1001]; //v[i] = (j,k) : i부터 j까지 k의 거리
int dist[1001]; // i -> j 까지 최소 거리
int result[1001]; // i -> X - > i의 거리

void dijk(int start) {
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });
	while (!q.empty()) {
		int d = q.top().first;
		int x = q.top().second;
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int nd = v[x][i].second;
			if (dist[nx] == -1 || dist[nx] > d + nd) {
				dist[nx] = d + nd; //현재까지 거리 + 다음 위치까지 거리
				q.push({ dist[nx],nx });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		dijk(i);
		result[i] = dist[X]; // i -> X 까지 거리 기록
	}

	dijk(X);
	for (int i = 1; i <= N; i++)  // X -> i 까지 거리 추가
		result[i] += dist[i];

	for (int i = 1; i <= N; i++) // i -> X -> i 거리 중 최대값 구하기
		res = max(res, result[i]);
	
	cout << res;
}
