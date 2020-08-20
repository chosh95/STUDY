#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v[1001];
vector<int> res;
int indeg[1001]; //indegree 위상

void bfs() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indeg[next]--;
			if (indeg[next] == 0) {
				q.push(next);
			}
		}
	}

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		cin >> cnt;
		int cur, next;
		cin >> cur;
		for (int j = 1; j < cnt; j++) {
			cin >> next;
			v[cur].push_back(next);
			indeg[next]++;
			cur = next;
		}
	}

	bfs();

	// cycle이 생겨 indeg가 0인 노드가 없는 경우.
	if (res.size() != N) cout << "0";
	else {
		for (int i = 0; i < N; i++) {
			cout << res[i] << "\n";
		}
	}
}