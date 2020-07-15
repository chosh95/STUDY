#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, R, res;
int t[110];
vector<pair<int,int>> v[110]; // v[a] = (c,b) : a에서 b까지 c의 거리로 이동 가능
int dist[110];

void dijk(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push({ 0,start }); //거리, 도시
	while (!q.empty()) {
		int cur = q.top().first;
		int city = q.top().second;
		q.pop();
		for (int i = 0; i < v[city].size(); i++) {
			int nextDist = v[city][i].first + cur;
			int nextCity = v[city][i].second;
			if (nextDist > M) continue; //거리가 M이상이면 건너뛴다.
			if (dist[nextCity] > nextDist) {
				dist[nextCity] = nextDist;
				q.push({ nextDist, nextCity });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) cin >> t[i];
	for (int a, b, c, i = 1; i <= R; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) dist[j] = 987654321; // 거리 초기화

		dijk(i); // i 도시에서 시작하는 다익스트라

		int tmp = 0;
		for (int j = 1; j <= N; j++) 
			if (dist[j] <= M) tmp += t[j]; // 얻을 수 있는 아이템 수 계산
		
		res = max(res, tmp);
	}
	cout << res;
}