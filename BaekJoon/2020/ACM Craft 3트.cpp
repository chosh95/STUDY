#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int T;
int N, K, W;
int D[1001];
int cost[1001];
vector<int> v[1001];
int indeg[1001];

void bfs()
{
	queue<pair<int, int>> q; // 현재 지점, 소요 시간
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push({ i,D[i] });

	while (!q.empty()) {
		int cur = q.front().first;
		int curCost = q.front().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			int nextCost = curCost + D[next];
			cost[next] = max(cost[next], nextCost);
			indeg[next]--;
			if (indeg[next] == 0)
				q.push({ next, cost[next] });
		}
	}

}

int main()
{
	cin >> T;
	while (T--) {
		memset(indeg, 0, sizeof(indeg));
		memset(cost, 0, sizeof(cost));
		memset(D, 0, sizeof(D));
		for (int i = 0; i <= 1000; i++) v[i].clear();

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> D[i];
			cost[i] = D[i];
		}
		for (int x, y, i = 1; i <= K; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			indeg[y]++;
		}
		cin >> W;

		bfs();

		cout << cost[W] << "\n";
	}
}